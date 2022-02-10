//https://cses.fi/problemset/task/1688
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int mxn = 2e5+1;
int ln = 21;
vector<vector<int>>adj(mxn);
vector<vector<int>>dp(ln+1, vector<int>(mxn));
vector<int>lvl(mxn);

void dfs(int u, int p){
    for(int i=1;i<=ln;i++){
        dp[i][u] = dp[i-1][dp[i-1][u]];
    }

    for(int nxt: adj[u]){
        if(nxt == p)continue;
        dp[0][nxt] = u;
        lvl[nxt] = lvl[u] + 1;
        dfs(nxt, u);
    }
    return;
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]){
        swap(x, y);
    }
    int diff = lvl[x] - lvl[y];

    for(int i=0;i<=ln;i++){
        if(diff&(1<<i)){
            x = dp[i][x];
        }
    }
    if(x == y)return x;

    for(int i = ln; i>=0;i--){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, 0);
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<lca(x, y)<<"\n";
    }

    return 0;
}