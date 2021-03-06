//https://dmoj.ca/problem/dmpg17s2

#include <bits/stdc++.h>
using namespace std;

#define int long long

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
        if(x==y)return ;

        if(sz[x]<sz[y]){
            parent[x] = y;
            sz[y] += sz[x];

        }
        else{
            parent[y] = x;
            sz[x] += sz[y];
        }
    }

};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;

    DSU ds;
    ds.init(n);

    while(q--){
        char c; cin>>c;
        int x, y;
        cin>>x>>y;

        if(c=='A') ds.Union(x,y);
        else{
            if(ds.find(x)==ds.find(y))cout<<"Y\n";
            else cout<<"N\n";
        }
    }



    return 0;
}