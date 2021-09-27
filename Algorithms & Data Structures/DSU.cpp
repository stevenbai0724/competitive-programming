//https://dmoj.ca/problem/sac21ccp5
//template DSU problem 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    DSU ds;
    ds.init(n);
    while(m--){
        int o; cin>>o;
        if(o==1){
            int x, y;
            cin>>x>>y;
            ds.Union(x, y);
        }
        else{
            int x; cin>>x;
            cout<<ds.getSize(x)<<"\n";
        }
    }


    return 0;
}