
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

    vector<vector<int>>adj(n+5, vector<int>(m+6));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = (int)1e18;
        }
    }

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x][y] = min(adj[x][y], w);

    }

    
    vector<vector<int>>dis(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j)continue;
            dis[i][j] = 1e18;
        }
    }
    int k, q;
    cin>>k>>q;

    for(int START = 1; START <= n; START++){
        vector<bool>vis(n+1);
        vector<int>used(n+1, 1e18);
        int nxt = START;
        vis[START] = true;
        used[START] = 0;
        for(int i=1;i<n;i++){
            pair<int, int>mn {1e18, START};
            vis[nxt] = true;
            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                if(dis[START][nxt] + adj[nxt][j] < dis[START][j]){
                    dis[START][j] = dis[START][nxt] + adj[nxt][j];
                    used[j] = used[nxt] + 1;
                }
                else if(dis[START][nxt] + adj[nxt][j] == dis[START][j]){
                    used[j] = min(used[j], used[nxt] + 1);
                }
                if(used[j] < k)mn = min(mn, {dis[START][j], j});
            }
            nxt = mn.second;
        }
    }
    

    while(q--){
        int x, y;
        cin>>x>>y;
        if(dis[x][y] == 1e18)cout<<-1<<"\n";
        else cout<<dis[x][y]<<"\n";
    }
    return 0;
}
/*

5 5 
1 2 72
2 3 54
1 4 10
4 5 10
5 3 20
2 2
1 3
1 5



*/