//https://dmoj.ca/problem/tle17c3p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

int dfs(int v, vector<vector<int>>&adj, vector<int>&weight, vector<int>&colour){
    colour[v] = 1;
    int mn = 1e18;
    if(adj[v].empty()){
        colour[v] = 2;
        return weight[v];
    }
    for(int u: adj[v]){
        if(colour[u] == 0){
            mn = min(mn, dfs(u, adj, weight, colour));
        }
    }
    colour[v] = 2;
    return weight[v] + mn;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>weight(n+1), colour(n+1);

    for(int i=1;i<=m;i++){
        int x, j;
        cin>>x>>j;
        while(j--){
            int y; cin>>y;
            adj[x].push_back(y);
        }
    }

    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }

    cout<<dfs(1, adj, weight, colour)<<"\n";




    return 0;
}