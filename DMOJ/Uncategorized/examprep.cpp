//https://dmoj.ca/problem/examprep
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct DSU{
    vector<int>parent, sz, val;

    void init(int n, vector<int>temp){
        parent.resize(n+1);
        sz.resize(n+1);
        val = temp;
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
            val[y] += val[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            val[x] += val[y];
            parent[y] = x;
        }
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    DSU ds;
    ds.init(n, val);

    while(q--){
        int a; cin>>a;
        if(a==1){
            int x, y;
            cin>>x>>y;
            ds.Union(x, y);
        }
        if(a==2){
            int x; cin>>x;
            cout<<ds.sz[ds.find(x)]<<"\n";
        }
        if(a==3){
            int x; cin>>x;
            cout<<ds.val[ds.find(x)]<<"\n";
        }
    }

    return 0;
}