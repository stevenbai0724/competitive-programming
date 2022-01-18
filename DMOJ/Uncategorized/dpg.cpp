//https://dmoj.ca/problem/dpg
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


void dfs(int v, vector<int>&dp, vector<int>&colour, vector<vector<int>>&adj){
    colour[v] = 1;

    for(int u: adj[v]){
        if(colour[u] == 0){
            dfs(u, dp, colour, adj);
            
        }
        dp[v] = max(dp[v], 1 + dp[u]);
    }

    colour[v] = 2;


}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<int>dp(n+1);
    vector<int>colour(n+1);

    for(int i=1;i<=n;i++){
        if(!colour[i])dfs(i, dp, colour, adj);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans<<"\n";


    return 0;
}
