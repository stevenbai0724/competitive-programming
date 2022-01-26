//https://judge.yosupo.jp/problem/lca
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
int ln = 31;
int mxn = 5e5 + 5;
vector<vector<int>>adj(mxn);
vector<vector<int>>dp(ln, vector<int>(mxn));
vector<int>dis(mxn);
void dfs(int u, int p){

    dp[0][u] = p;

    for(int i=1;i<ln;i++){
        dp[i][u] = dp[i-1][dp[i-1][u]];
    }

    for(int nxt: adj[u]){
        if(nxt == p)continue;
        dis[nxt] = dis[u] +1;
        dfs(nxt, u);
    }

    return;
}
int lca(int x, int y){
    if(dis[x] < dis[y]){
        swap(x, y);
    }
    int diff = dis[x] - dis[y];
    for(int i=0;i<ln;i++){
        if((1<<i)&diff){
            x = dp[i][x];
        }
    }

    if(x == y)return x;

    for(int i=ln-1;i>=0;i--){
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
        x++;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1, 0);
    while(q--){
        int x, y;
        cin>>x>>y;
        x++;
        y++;
        cout<<lca(x, y)-1<<"\n";
    }


    return 0;
}
