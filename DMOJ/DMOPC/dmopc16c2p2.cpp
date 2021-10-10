//https://dmoj.ca/problem/dmopc16c2p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

struct DSU{
    vector<int>parent, sz;
    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1, 1);

        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x ) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return;

        if(sz[x]<sz[y] ){
            sz[y] += sz[x];
            parent[x] = y;
        }
        else if(sz[x]>=sz[y]){
            sz[x] += sz[y];
            parent[y] = x;
        }
    }
};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    DSU ds;
    ds.init(n);
    while(m--){
        int k; cin>>k;
        if(k==0)continue;
        int prev; cin>>prev;
        for(int i=2;i<=k;i++){
            int x; cin>>x;
            ds.Union(x, prev);
            prev = x;
        }
    }
    vector<int>ans{1};
    int pt = ds.find(1);

    for(int i=2;i<=n;i++){
        if(ds.find(i)==pt)ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";



    return 0;
}