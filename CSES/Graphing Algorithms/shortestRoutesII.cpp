//https://cses.fi/problemset/task/1672
//TLE, 14 out of 15 points
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, que;
    cin>>n>>m>>que;
    vector<vector<pair<int, int>>>adj(n+1);
    vector<vector<int>>dis(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j] = 1e18;
        }
    }
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }
    for(int i=1;i<=n;i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        vector<int>vis(n+1);
        q.push({0,i});
        while(!q.empty()){
            int y = q.top().second;
            int w = q.top().first;
            q.pop();
            if(vis[y])continue;
            vis[y] =true;
            for(auto x : adj[y]){
                int neww = x.first;
                int newy = x.second;
                if(dis[i][y] + neww < dis[i][newy]){
                    dis[i][newy] = w + neww;
                    q.push({dis[i][newy], newy});
                }
            }
        }
    }
    for(int i=1;i<=que;i++){
        int a, b;
        cin>>a>>b;
        if(dis[a][b]==1e18)cout<<-1<<"\n";
        else cout<<dis[a][b]<<"\n";
    }



    return 0;
}
