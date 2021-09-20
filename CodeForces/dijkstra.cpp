//https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
        
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;   
    vector<int>dis(n+1, 1e18);
    vector<int>vis(n+1);
    vector<int>p(n+1);
    for(int i=1;i<=m;i++){
        int x, y,w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    dis[1] = 0;
    q.push({0,1});

    while(!q.empty()){
        int y = q.top().second;
        int w = q.top().first;
        q.pop();
        if(vis[y])continue;
        vis[y] = true;
        for(auto x : adj[y]){
            int newy = x.second;
            int neww = x.first;
            if(dis[y]+neww<dis[newy]){
                dis[newy] = dis[y] + neww;
                q.push({dis[newy], newy});
                p[newy] = y;
            }
        }
    }
    if(!vis[n]){
        cout<<-1;
        return 0;
    }
    vector<int>ans; ans.push_back(n);
    int cur = n;
    while(cur!=1){
        cur = p[cur];
        ans.push_back(cur);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }

    return 0;
}