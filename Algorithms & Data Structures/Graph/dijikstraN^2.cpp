//dijikstra's shortest path algorithm, n^2
//https://dmoj.ca/problem/sssp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = (int)1e9;
        }
    }

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x][y] = min(adj[x][y], w);
        adj[y][x] = min(adj[y][x], w);
    }

    vector<int>dis(n+1, (int)1e9);
    vector<bool>vis(n+1);
    dis[1] = 0;
    int nxt = 1;
    pair<int, int>mn = {(int)1e9, nxt};

    for(int i=1;i<n;i++){
        vis[nxt] = true;
        mn = {(int)1e9, nxt};
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            if(dis[j] > adj[nxt][j] + dis[nxt]){
                dis[j] = adj[nxt][j] + dis[nxt];
            }
            mn = min(mn, {dis[j], j});
        }
        nxt = mn.second;
    }
    for(int i=1;i<=n;i++){
        if(dis[i]==(int)1e9)cout<<-1<<"\n";
        else cout<<dis[i]<<"\n";
    }






    return 0;
}