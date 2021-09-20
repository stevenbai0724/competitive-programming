//https://codeforces.com/problemset/problem/449/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, k;
    cin>>n>>m>>k;
    int ans = 0;
    vector<vector<pair<int, int>>>adj(n+1); //train
    vector<vector<pair<int, int>>>adj2(n+1); //no train
    vector<int>dis(n+1, 1e18);
    vector<int>dis2(n+1, 1e18);
    vector<bool>vis(n+1, false);
    vector<bool>vis2(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    dis[1] = 0;
    dis2[1] = 0;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
        adj2[x].push_back({w,y});
        adj2[y].push_back({w,x});
    }
    while(k--){
        int y,w;
        cin>>y>>w;
        adj[1].push_back({w,y});
        adj[y].push_back({w,1});
    }
    q.push({0,1});

    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis[y])continue;
        vis[y] = true;
        for(auto x: adj[y]){
            int newy = x.second;
            int neww = x.first;
            if(neww + dis[y]<dis[newy]){
                dis[newy] = neww + dis[y];
                q.push({dis[newy], newy});
            }
        }
    }
    q.push({0,1});
    while(!q.empty()){
        int y = q.top().second;
        q.pop();
        if(vis2[y])continue;
        vis2[y] = true;
        for(auto x: adj2[y]){
            int newy = x.second;
            int neww = x.first;
            if(neww + dis2[y]<dis2[newy]){
                dis2[newy] = neww + dis2[y];
                q.push({dis2[newy], newy});
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(dis[i]>=dis2[i] && adj[i].size()>adj2[i].size())ans++;
    }
    cout<<ans;
  

    return 0;
}