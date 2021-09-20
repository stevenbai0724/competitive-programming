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
    vector<int>parent, sz;
    int size;

    void init(int n){
        size = n;
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

        if(x==y)return;
        if(sz[x]<sz[y]){
            parent[x] = y;
            sz[y] += sz[x];
        }
        else{
            parent[y] = x;
            sz[x] = sz[y];
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
        string s; cin>>s;
        int x, y;
        cin>>x>>y;
        if(s=="union"){
            ds.Union(x, y);
        }
        else{
            int a = ds.find(x);
            int b = ds.find(y);

            if(a==b)cout<<"YES\n";
            else cout<<"NO\n";

        }
    }

    return 0;
}
