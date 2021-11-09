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
        if(parent[x] == x)return x;
        return find(parent[x]);
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
};
bool comp(edge a, edge b){
    return a.w>b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, d;
    cin>>n>>m>>d;
    DSU ds;
    ds.init(n);

    vector<edge>arr;
    vector<int>des;
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        edge e = {x,y,w};
        arr.push_back(e);
    }

    des.push_back(1);
    for(int i=1;i<=d;i++){
        int wer; cin>>wer;
        des.push_back(wer);
    }   

    int lo = 0;
    int hi = (int)1e6+3;

    int t = 70;
    while(t--){
        int mid = (lo+hi)/2;
        for(auto e: arr){
            if(e.w<mid)continue;
            ds.Union(e.x, e.y);
        }
        bool good = true;
        int check = ds.find(1);
        for(auto x : des){
            good = good && (check == ds.find(x));
        }

        if(good)lo = mid;
        else hi = mid;

        ds.init(n);
    }
    cout<<lo<<"\n";


    return 0;
}