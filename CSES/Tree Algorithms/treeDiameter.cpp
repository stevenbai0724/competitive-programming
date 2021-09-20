//https://cses.fi/problemset/task/1131
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>dis;
int nd, mx = 0;

void bfs(int v){
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), 0);
    mx = 0;
    queue<int>q;
    q.push(v);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        vis[cur] = true;
        for(auto x: adj[cur]){
            if(!vis[x]){
                vis[x] = true;
                dis[x] = dis[cur]+1;
                q.push(x);
                if(dis[x]>mx){
                    nd =x;
                    mx = dis[x];
                }
            }
        }
    }   
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1);
    dis.resize(n+1);
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    bfs(nd);
    cout<<mx<<"\n";


    return 0;
}
