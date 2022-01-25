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
int mxn = 2e5 + 4;
vector<vector<int>>adj(mxn);
vector<int>dis(mxn);
void dfs(int u, int p){
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        dis[nxt] = dis[u] + 1;
        dfs(nxt, u);
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
    }

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    dfs(1,0);

    cout<<0;

    for(int i=2;i<=n;i++){
        cout<<" "<<(dis[i]+d-1)/d;
    }
    cout<<"\n";



    return 0;
}
