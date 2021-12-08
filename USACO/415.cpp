//http://www.usaco.org/index.php?page=viewproblem2&cpid=415
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct DSU {
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
    void Union (int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return ;

        if(sz[x] < sz[y]){
            parent[x] = y;
            sz[y] += sz[x];
        }
        else{
            parent[y] = x;
            sz[x] += sz[y];
        }
    }
    int getSize(int x){
        return sz[find(x)];
    }

};
struct edge{
    int x, y, w;
};
bool comp(edge a, edge b){
    return a.w < b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);

    int n, k;
    cin>>n>>k;
    vector<pair<int, int>>points{{0,0}};
    vector<edge>use;
    DSU ds;
    ds.init(n);

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    for(int i=1;i<n;i++){
        for(int j = i+1;j<=n;j++){
            if(i == j)continue;
            int x1 = points[i].first;
            int x2 = points[j].first;
            int y1 = points[i].second;
            int y2 = points[j].second;
            int X = x1 - x2;
            int Y = y1 - y2;
            if(X*X + Y*Y >= k)use.push_back({i, j, X*X + Y*Y});
        }
    }
    sort(use.begin(), use.end(), comp);

    int ans = 0;
    
    for(auto e: use){
        int w = e.w;
        int x = e.x;
        int y = e.y;
        if(ds.find(y) == ds.find(x))continue;
        if(ds.getSize(1) == n)break;
        ds.Union(x, y);
        ans += w;
    }
    cout<<(ds.getSize(1) != n ? -1 : ans)<<"\n";
  



    return 0;
}