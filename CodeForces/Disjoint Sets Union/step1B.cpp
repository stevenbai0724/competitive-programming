//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

struct DSU{
    vector<int>parent, sz, mx, mn;

    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        mx.resize(n+1);
        mn.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
            mx[i] = mn[i] = i;
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

        if(x==y)return;
        if(sz[x]<sz[y]){
            parent[x] = y;
            mx[y] = max(mx[y], mx[x]);
            mn[y] = min(mn[y], mn[x]);
            sz[y]+=sz[x];
        }
        else{
            parent[y] = x;
            mx[x] = max(mx[y], mx[x]);
            mn[x] = min(mn[y], mn[x]);
            sz[x]+=sz[y];
        }

    }
    int getMx(int x){ return mx[find(x)];}
    int getMn(int x){ return mn[find(x)];}
    int getSz(int x){ return sz[find(x)];}
};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;

    DSU ds;
    ds.init(n);

    while(q--){
        string s; cin>>s;
        if(s=="union"){
            int x, y;
            cin>>x>>y;
            ds.Union(x, y);
        }
        else{
            int x; cin>>x;
            cout<<ds.getMn(x)<<" "<<ds.getMx(x)<<" "<<ds.getSz(x)<<"\n";
        }
    }
    

    return 0;
}