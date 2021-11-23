//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
int START = 0;
int mx = 0;
void dfs(int v, vector<vector<pair<int,int>>>&adj, vector<int>&dis, vector<int>&colour){
    colour[v] = 1;
    for(auto u: adj[v]){
        if(colour[u.first] == 0){
            dis[u.first] = dis[v] + u.second;
            if(dis[u.first] > mx){
                mx = dis[u.first];
                START = u.first;
            }
            dfs(u.first, adj, dis, colour);

        }
    }
    colour[v] = 2;
    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    vector<int>dis(n+1), colour(n+1);
    vector<int>arr(n);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
        arr[i] = w;
    }
    sort(arr.begin(), arr.end());
    if(m != 1){
        cout<<arr[n-m]<<"\n";
        return 0;
    }

    dfs(1, adj, dis, colour);

    fill(dis.begin(), dis.end(), 0);
    fill(colour.begin(), colour.end(), 0);

    mx = 0;

    dfs(START, adj, dis, colour);

    cout<<mx<<"\n";




    return 0;
}