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
struct DSU{
    vector<int>parent, sz;

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
            parent[x] = y;
            sz[y] += sz[x];
        }
        else{
            parent[y] = x;
            sz[x] += sz[y];
        }
    }
};
struct edge{
    int x, y;
    double d;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    DSU ds;
    ds.init(n);

    vector<pair<double, double>>nodes(n+1);
    vector<edge>edges;

    for(int i=1;i<=n;i++){
        double x, y;
        cin>>x>>y;
        nodes[i] = {x,y};
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            double a = nodes[i].first;
            double b = nodes[i].second;
            double c = nodes[j].first;
            double d = nodes[j].second;

            double X = abs(a-c);
            double Y = abs(b-d);

            edges.push_back({i, j, sqrt(X*X + Y*Y)});
        }
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b){
        return a.d < b.d;
    });

    int m; cin>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        ds.Union(x, y);
    }
    double ans = 0;
    vector<pair<int, int>>add;
    for(auto e: edges){
        int x = e.x;
        int y = e.y;
        double d = e.d;

        if(ds.find(x) != ds.find(y)){
            ds.Union(x, y);
            add.push_back({x,y});
            ans += d;
        }
    }

    cout<<fixed<<setprecision(2)<<ans<<"\n";

    for(auto p: add){
        cout<<p.first<<" "<<p.second<<"\n";
    }

    return 0;
}
