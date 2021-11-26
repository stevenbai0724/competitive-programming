//http://www.usaco.org/index.php?page=viewproblem2&cpid=788
//USACO 2018 January Contest Silver P3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
void dfs(int v, vector<vector<pair<int, int>>>&adj, vector<int>&colour, vector<int>&dis){
    colour[v]  = 1;
    for(auto p: adj[v]){
        int u = p.first;
        int w = p.second;
        if(colour[u] == 0){
            dis[u] = min(dis[v], w);
            dfs(u, adj, colour, dis);
        }
    }
    colour[v] = 2;

    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    
    int n, q;
    cin>>n>>q;
    vector<vector<pair<int, int>>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    while(q--){
        int k, v;
        cin>>k>>v;
        vector<int>colour(n+1), dis(n+1);
        dis[v] = 1e18;
        dfs(v, adj, colour, dis);   
        int cnt = -1;

        for(int i=1;i<=n;i++){
            cnt += (dis[i]>=k);
        }
        cout<<cnt<<"\n";
        
    }

    return 0;
}