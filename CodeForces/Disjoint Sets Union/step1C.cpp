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
int ans = 0;
struct DSU{

    vector<int>points, parent, sz;

    void init(int n){
        points.resize(n+1);
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return;
        if(sz[x]<sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
            points[x] -= points[y];
        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
            points[y] -= points[x];
        }
        
    }
    void add(int x, int v){
        points[find(x)] += v;
    }
    void get(int x){
        
        ans += points[x];
        if(parent[x]==x)return;
        get(parent[x]);
        

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
        if(s=="join"){
            int x, y;
            cin>>x>>y;
            ds.Union(x, y);
        }
        else if(s=="add"){
            int x, v;
            cin>>x>>v;
            ds.add(x, v);
        }
        else{
            int x; cin>>x;
            ds.get(x);
            cout<<ans<<"\n";
            ans = 0;
        }
    }


    return 0;
}