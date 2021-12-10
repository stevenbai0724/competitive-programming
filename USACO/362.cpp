//http://www.usaco.org/index.php?page=viewproblem2&cpid=362&lang=en
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

    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);
    
    int n, m, k, q;
    cin>>n>>m>>k>>q;

    vector<vector<int>>adj(n+2, vector<int>(n+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = 1e9;
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
            dis[i][j] = 1e9;
            if(i == j)dis[i][j] = 0;
        }
    }

    for(int START = 1; START <= n; START++){
        vector<bool>vis(n+1);
        int nxt = START;
        vis[nxt] = true;

        for(int i=1;i<n;i++){
            vis[nxt] = true;
            pair<int, int>mn{1e18, START};
            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                if(dis[START][nxt] + adj[nxt][j] < dis[START][j]){
                    dis[START][j] = dis[START][nxt] + adj[nxt][j];
                }
                mn = min(mn, {dis[START][j], j});
            }
            nxt = mn.second;
        }

    }
    int cnt = 0;
    int sum = 0;
    while(q--){
        int x, y;
        cin>>x>>y;
        int mn = 1e9;
        for(int i=1;i<=k;i++){
            mn = min(mn, dis[x][i] + dis[i][y]);
        }
        if(mn!=1e9){
            cnt++;
            sum += mn;
        }

    }
    cout<<cnt<<"\n"<<sum<<"\n";



    return 0;
}