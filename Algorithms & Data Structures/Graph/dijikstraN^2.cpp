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

    vector<vector<int>>adj(n+5, vector<int>(m+6));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = (int)1e9;
        }
    }

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x][y] = min(adj[x][y], w);

    }

    vector<bool>vis(n+5);
    vector<int>dis(n+5, 1e18);

    dis[1] = 0;

    int nxt = 1;

    for(int i=1;i<n;i++){
        vis[nxt] = true;
        pair<int, int>mn = {1e18, 0};
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            if(dis[j] > dis[nxt] + adj[nxt][j]){
                dis[j] = dis[nxt] + adj[nxt][j];
            }
            mn = min(mn, {dis[j], j});
        }
        nxt = mn.second;
    }

    for(int i=1;i<=n;i++){
        cout<<(dis[i] == 1e9 ? -1 : dis[i])<<"\n";
    }

    return 0;
}