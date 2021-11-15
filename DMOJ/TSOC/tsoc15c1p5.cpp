//https://dmoj.ca/problem/tsoc15c1p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }  
    vector<int>ant(n+1, 1e18);

    int w; cin>>w;
    while(w--){
        int a; cin>>a;
        ant[a] = 0;
        queue<int>q;
        vector<int>vis(n+1);
        q.push(a);
        vis[a] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    ant[nxt] = min(ant[nxt], ant[cur]+1);
                    q.push(nxt);
                }
            }
        }
    }
    vector<int>dis(n+1);
    vector<int>vis(n+1);
    queue<int>q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                dis[nxt] = dis[cur] + 1;
                if(dis[nxt]/4<ant[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }
    if(vis[n])cout<<dis[n]<<"\n";
    else cout<<"sacrifice bobhob314\n";



    return 0;
}