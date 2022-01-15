//https://atcoder.jp/contests/abc235/tasks/abc235_e
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
    int x, y, w, id, t;
};
bool comp(edge a, edge b){
    return a.w < b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q;
    cin>>n>>m>>q;

    DSU ds;
    ds.init(n);

    vector<edge>adj;

    for(int i=1;i<=(m+q);i++){
        int x, y, w;
        cin>>x>>y>>w;
        int t; 
        if(i <= m)t = 1;
        else t = 2;
        adj.push_back({x,y,w,i,t});
    }
    
    sort(adj.begin(), adj.end(), comp);

    vector<bool>use(m+q+1);

    for(edge e: adj){
        int x = e.x;
        int y = e.y;
        int w = e.w;
        int id = e.id;
        int t = e.t;

        if(t == 1){
            if(ds.find(x) != ds.find(y))ds.Union(x, y);
        }
        else{
            if(ds.find(x) != ds.find(y)){
                use[id] = true;
            }
        }
    }

    for(int i=m+1;i<=m+q;i++){
        if(use[i])cout<<"Yes\n";
        else cout<<"No\n";
    }



    return 0;
}
