//https://dmoj.ca/problem/brittlebridges
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
int n;
struct DSU{
    vector<int>parent, sz, weight;
    void init(int n, vector<int>val){
        parent.resize(n+1);
        sz.resize(n+1);
        weight = val;
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
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            weight[y] += weight[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            weight[x] += weight[y];
            parent[y] = x;
        }
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    vector<int>val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    DSU ds;
    ds.init(n, val);

    vector<set<int>>adj(n+1);
    vector<int>dis(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].insert(y);
        adj[y].insert(x);

        if(w > 1)ds.Union(x, y);

    }
    queue<int>q;
    vector<bool>vis(n+1);
    for(int i=1;i<=n;i++){
        int parent = ds.find(i);
        for(int x: adj[i]){
            adj[parent].insert(x);
        }
    }

    int START = ds.find(1);

    vis[START] = true;
    q.push(START);
    dis[START] = ds.weight[START];
    int mx = dis[START];

    while(!q.empty()){
        int cur = q.front();
        cur = ds.find(cur);
        q.pop();
        for(int nxt: adj[cur]){
            nxt = ds.find(nxt);
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt] = ds.weight[nxt] + dis[cur];
                mx = max(mx, dis[nxt]);
                q.push(nxt);
            }
        }
    }
    cout<<mx<<"\n";
    





/*
8
791095846 282876140 93770125 5303369 491264 550290314 298508492 29084634
4 5 1
2 1 13994433
3 6 18109722
5 8 345499494
6 7 1
3 2 799981517
3 4 1


*/







    return 0;
}