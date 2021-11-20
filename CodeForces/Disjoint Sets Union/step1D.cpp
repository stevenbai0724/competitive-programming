//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct DSU{
    vector<int>parent, sz;
    void init(int n){
        parent.resize(n+5);
        sz.resize(n+5);
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
        if(x == y)return ;
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

    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
    }

    DSU ds;
    ds.init(n);
    vector<pair<string, pair<int, int>>>queries;
    vector<string>ans;

    while(q--){
        string s; cin>>s;
        int x, y;
        cin>>x>>y;
        queries.push_back({s,{x,y}});
    }

    std::reverse(queries.begin(), queries.end());

    for(auto p: queries){
        if(p.first == "ask"){
            if(ds.find(p.second.first) == ds.find(p.second.second)) ans.push_back("YES\n");
            else ans.push_back("NO\n");
        }
        else{
            ds.Union(p.second.first, p.second.second);
        }
    }
    std::reverse(ans.begin(), ans.end());
    for(auto s: ans){
        cout<<s;
    }


    return 0;
}