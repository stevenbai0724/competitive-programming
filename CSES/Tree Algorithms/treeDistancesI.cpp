//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>dis(n+1), dis2(n+1);
    vector<bool>vis(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int>q;
    q.push(1);
    vis[1] = true;
    int mx = 0;
    int START = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[cur] + 1;
                if(dis[nxt]>mx){
                    mx = dis[nxt];
                    START = nxt;
                }
                q.push(nxt);
            }
        }
    }
    q.push(START);
    mx = 0;
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), 0);
    vis[START] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis[nxt] = dis[cur] + 1;
                if(dis[nxt] > mx){
                    mx = dis[nxt];
                    START = nxt;
                }
                q.push(nxt);
            }
        }
    }
    fill(vis.begin(), vis.end(), false);

    q.push(START);
    vis[START] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                dis2[nxt] = dis2[cur] + 1;
                q.push(nxt);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<max(dis[i], dis2[i])<<" ";
    }
    cout<<"\n";



    return 0;
}