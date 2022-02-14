//https://dmoj.ca/problem/sac22cc3p4
#include <bits/stdc++.h>
using namespace std;
#define int long long

int mxn = 2e5;
vector<vector<int>>adj(mxn+1);
vector<int>lvl(mxn+1);
int ln = 25;
vector<vector<int>>dp(ln+1, vector<int>(mxn+1));

void dfs(int u, int p){
    for(int i=1;i<=ln;i++){
        dp[i][u] = dp[i-1][dp[i-1][u]];
    }
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        lvl[nxt] = lvl[u] +  1;
        dp[0][nxt] = u;
        dfs(nxt, u);
    }
    return;
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]){
        swap(x, y);
    }
    int diff = lvl[x] - lvl[y];

    for(int i = ln;i>=0;i--){
        if(diff & (1<<i))x = dp[i][x];
    }
    if(x == y)return x;

    for(int i=ln;i>=0;i--){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }

    return dp[0][x];
}
int dis(int x, int y){
    return lvl[x] + lvl[y] - 2*lvl[lca(x, y)];
}
struct DSU{
    vector<int>parent;
    vector<int>sz;
    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }

    }
    int find(int x){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
        }
    }

};
struct Query{
    int k, x, y;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);

    vector<Query>arr;
    vector<int>ans;

    for(int i=1;i<=q;i++){
        int k, x, y;
        cin>>k>>x>>y;
        arr.push_back({k,x,y});
    }

    reverse(arr.begin(), arr.end());

    DSU ds;
    ds.init(n);
    for(auto Q: arr){
        int k = Q.k;
        int x = Q.x;
        int y = Q.y;

        if(k == 1){
            if(ds.find(x) != ds.find(y))ans.push_back(-1);
            else{
                ans.push_back(dis(x, y));
            }
        }
        else{
            ds.Union(x, y);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans)cout<<x<<"\n";


    return 0;
}
