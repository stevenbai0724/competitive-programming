//https://atcoder.jp/contests/abc231/tasks/abc231_d
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool good = true;
void dfs(int v, int p, vector<int>&colour, vector<vector<int>>&adj){
    colour[v] = 1;
    for(int u: adj[v]){
        if(u == p)continue;
        if(colour[u] == 0){
            dfs(u,v, colour, adj);
        }
        else if(colour[u] == 1){
            good = false;
        }
    }
    colour[v] = 2;
    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>colour(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(adj[x].size() >=3 || adj[y].size() >=3){
            cout<<"No\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(colour[i] == 0){
            dfs(i,-1, colour, adj);
        }
    }
    if(good)cout<<"Yes\n";
    else cout<<"No\n";


    return 0;
}