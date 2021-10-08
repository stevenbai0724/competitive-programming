//https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, que;
    cin>>n>>m>>que;
    
    vector<vector<int>>adj(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = 1e18;
        }
    }
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x][y] = min(adj[x][y], w);
        adj[y][x] = min(adj[y][x], w);
    }

    vector<vector<int>>dis(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = 1e18;
        }
    }
    for(int START=1;START<=n;START++){
        vector<bool>vis(n+1);

        dis[START][START] = 0;

        int nxt = START;
        pair<int, int>mn = {1e18, START};

        for(int i=1;i<n;i++){
            vis[nxt] = true;
            mn = {1e18, START};

            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                if(dis[START][j] > dis[START][nxt] + adj[nxt][j]){
                    dis[START][j] = dis[START][nxt] + adj[nxt][j];
                }
                mn = min(mn, {dis[START][j], j});
            }
            nxt = mn.second;

        }

    }

    while(que--){
        int x, y;
        cin>>x>>y;
        if(dis[x][y] == 1e18)cout<<-1<<"\n";
        else cout<<dis[x][y]<<"\n";
        assert(dis[x][y] == dis[y][x]);
    }



    return 0;
}
