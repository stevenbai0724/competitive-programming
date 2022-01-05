//
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

void dfs(int v, vector<vector<int>>&adj, vector<int>&colour, vector<int>&dis){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u] == 0){
            dis[u] = dis[v] + 1;
            dfs(u, adj, colour, dis);
        }
    }
    colour[v] = 2;
    return; 
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, a, b;
    cin>>n>>a>>b;

    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        string s; cin>>s;
    }
    vector<int>dis(n+1);
    vector<int>colour(n+1);

    dfs(a, adj, colour, dis);

    if(dis[b]&1)cout<<"Marin\n";
    else cout<<"Paula\n";


    return 0;
}
