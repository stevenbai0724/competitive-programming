//http://www.usaco.org/index.php?page=viewproblem2&cpid=922
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct DSU{
    vector<int>parent, sz, badCount;
    vector<bool>bad;
    void init(int n, vector<bool>arr){
        bad = arr;
        parent.resize(n+1);
        sz.resize(n+1);
        badCount.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
            if(bad[i])badCount[i] = 1;
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
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            parent[x] = y;
            badCount[y] += badCount[x];
        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
            badCount[x] += badCount[y];
        }
    }
};
struct edge{
    int x, y, w;
};
bool comp(edge a, edge b){
    return a.w > b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, q;
    cin>>n>>q;

    DSU ds;
    
    vector<bool>bad(n+1);


    vector<int>arr(n+1), ind(n+1);
    int START;
    int good = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ind[arr[i]] = i;
        if(arr[i] != i){
            START = i;
            bad[i] = true;
        }
        else good ++ ;
    }
    ds.init(n, bad);

    if(good == n){
        cout<<-1<<"\n";
        return 0;
    }
    vector<edge>queries;

    for(int i=1;i<=q;i++){
        int x, y, w;
        cin>>x>>y>>w;
        queries.push_back({x,y,w});
    }
    sort(queries.begin(), queries.end(), comp);

    for(auto e: queries){
        int x = e.x;
        int y = e.y;
        int w = e.w;

        ds.Union(x, y);

        if(ds.badCount[ds.find(START)] + good == n){
            cout<<w<<"\n";
            break;
        }
        
    }


    

    return 0;
}