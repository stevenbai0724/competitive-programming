//https://dmoj.ca/problem/ccc17s4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

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
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return ;
        if(sz[x]<sz[y]){
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
    int id;
    bool use;
};
bool comp(edge a, edge b){  
    if(a.w<b.w)return true;
    else if(a.w>b.w)return false;
    else{
        if(a.use)return true;
        else return false;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, d;
    cin>>n>>m>>d;
    assert(m>=n-1);
    DSU ds;
    ds.init(n);

    vector<edge>arr;

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        assert(x!=y);
        
        edge e;
        e.x = x;
        e.y = y;
        e.w = w;
        e.id = i;

        e.use = i<=n-1;
        arr.push_back(e);


    }
    sort(arr.begin(), arr.end(), comp);

    int cnt = 0;

    for(auto e: arr){
        if(ds.find(e.x) == ds.find(e.y))continue;
        ds.Union(e.x, e.y);
        if(e.id>=n)cnt++;
    }
    cout<<cnt<<"\n";

    






    return 0;
}