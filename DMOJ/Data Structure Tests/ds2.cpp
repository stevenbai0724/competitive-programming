//https://dmoj.ca/problem/ds2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

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
        if(parent[x]==x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
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

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    DSU ds;
    int n, m;
    cin>>n>>m;
    ds.init(n);

    vector<int>ans;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        x = ds.find(x);
        y = ds.find(y);
        if(x!=y){
            ans.push_back(i);
            ds.Union(x, y);
        }
    }
    if(ds.sz[ds.find(1)]!=n){
        cout<<"Disconnected Graph\n";
    }   
    else{
        for(auto x: ans)cout<<x<<"\n";
    }

    



    return 0;
}