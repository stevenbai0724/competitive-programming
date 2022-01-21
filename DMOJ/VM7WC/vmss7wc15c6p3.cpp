//https://dmoj.ca/problem/vmss7wc15c6p3
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
void dfs(int v, vector<vector<int>>&adj, vector<int>&colour, vector<int>&dp){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u] == 0){
            dfs(u, adj, colour, dp);
            dp[v] += dp[u];
        }
    }
    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<int>colour(n+1);
    vector<int>val(n+1);
    vector<int>dp(n+1);

    for(int i=1;i<=n;i++){
        cin>>val[i];
        dp[i] = val[i];
    }
    dfs(1, adj, colour, dp);
    int ans = -1e18;
    for(int i=1;i<=n;i++)ans = max(ans, dp[i]);
    cout<<ans<<"\n";

    return 0;
}
