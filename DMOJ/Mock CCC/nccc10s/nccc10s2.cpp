//https://dmoj.ca/problem/nccc10s2
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
void dfs(int v, vector<vector<bool>>&adj, vector<int>&dp, vector<int>&colour, int m){
    colour[v] = 1;
    for(int u = 1; u<=m; u++){
        if(u == v || !adj[v][u])continue;
        if(colour[u] == 0){
            dfs(u, adj, dp, colour, m);
        }
        dp[v] = max(dp[v], 1 + dp[u]);
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<bool>>adj(m+1, vector<bool>(m+1));
    vector<int>dp(m+1);
    vector<int>colour(m+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            adj[i][j] = true;
        }
    }
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                int x = s[j] - 'A' + 1;
                int y = s[k] - 'A' + 1;

                adj[y][x] = false;
            }
        }
    }

    for(int i=1;i<=m;i++){
        if(colour[i] == 0)dfs(i, adj, dp, colour, m);
    }

    int ans = 0;

    for(int i=1;i<=m;i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans+1<<"\n";
    



    return 0;
}
