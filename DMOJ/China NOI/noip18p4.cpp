//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
vector<int>ans;
void dfs(int v, vector<set<int>>&adj, vector<int>&colour){

    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            ans.push_back(u);
            dfs(u, adj, colour);
        }
    }

    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<set<int>>adj(n+1);
    vector<int>colour(n+1);
    ans.push_back(1);


    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    dfs(1, adj, colour);

    for(int x: ans)cout<<x<<" ";
    cout<<"\n";


    return 0;
}