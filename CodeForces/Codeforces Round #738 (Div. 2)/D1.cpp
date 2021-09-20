//https://codeforces.com/contest/1559/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string

struct DSU{

    vector<int>parent, sz;
    int size;

    void init(int n){
        parent.resize(n+1);
        size = n;
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;

        }
    }
    int find (int x){
        if(parent[x] == x)return x;
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
            sz[x] += sz[y];
        }
    }

};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m1, m2;
    cin>>n>>m1>>m2;

    

    DSU D1, D2;
    D1.init(n);
    D2.init(n);

    for(int i=1;i<=m1;i++){
        int x, y;
        cin>>x>>y;
     
        D1.Union(x, y);
    }
    for(int i=1;i<=m2;i++){
        int x, y;
        cin>>x>>y;

        D2.Union(x, y);
    }


    vector<pair<int, int>>ans;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(D1.find(i)==D1.find(j) || D2.find(i)==D2.find(j))continue;

            ans.push_back({i,j});

            D1.Union(i, j);
            D2.Union(i, j);

        }
    }

    cout<<ans.size()<<"\n";
    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }




    return 0;
}