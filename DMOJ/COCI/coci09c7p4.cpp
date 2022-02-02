//https://dmoj.ca/problem/coci09c7p4
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
struct DSU{
    vector<int>sz, parent;
    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y)return;
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
        }
    }
};
struct edge{
    int x, y, w;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    DSU ds;
    ds.init(n);
    vector<pair<int, int>>X, Y, Z;

    for(int i=1;i<=n;i++){
        int x, y, z;
        cin>>x>>y>>z;
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }
    vector<edge>edges;
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for(int i=0;i<n-1;i++){
        if(true){
            int x = X[i].second;
            int y = X[i+1].second;
            int w = X[i+1].first - X[i].first;

            edges.push_back({x,y,w});
        }
        if(true){
            int x = Y[i].second;
            int y = Y[i+1].second;
            int w = Y[i+1].first - Y[i].first;

            edges.push_back({x,y,w});
        }
        if(true){
            int x = Z[i].second;
            int y = Z[i+1].second;
            int w = Z[i+1].first - Z[i].first;

            edges.push_back({x,y,w});
        }
    }

    sort(edges.begin(), edges.end(), [] (edge a, edge b) {
        return a.w < b.w;
    });
    int cnt = 0;
    for(auto e: edges){
        int x = e.x;
        int y = e.y;
        int w = e.w;

        if(ds.find(x) != ds.find(y)){
            cnt += w;
            ds.Union(x, y);
        }
    }
    cout<<cnt<<"\n";

    return 0;
}
