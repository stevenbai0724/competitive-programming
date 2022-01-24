#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
int ln = 20;
vector<vector<int>>adj(mxn);
vector<vector<int>>dp(mxn,vector<int>(ln));//dp[u][i] is 2^ith node above node u
vector<int>lvl(mxn);
int n,q;
void dfs(int u, int p){
    lvl[u] = lvl[p]+1;
    dp[u][0] = p;
    for(int i = 1; i<ln; i++){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs(nxt,u);
    }
}
int lca(int x, int y){
    if(lvl[x]<lvl[y]){
        swap(x,y);
    }
    int dif = lvl[x]-lvl[y];
    for(int i = 0; i<ln; i++){
        if(dif&(1<<i)){
            x = dp[x][i];
        }
    }
    if(x==y)return x;
    for(int i = ln-1; i>=0; i--){
        if(dp[x][i]!=dp[y][i]){
            x = dp[x][i]; y = dp[y][i];
        }
    }
    return dp[x][0];
}
int dist(int x, int y){
    return lvl[x]+lvl[y]-2*lvl[lca(x,y)];
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 2; i<=n; i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1,0);
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << lca(x,y) << "\n";
    }
    return 0;
}