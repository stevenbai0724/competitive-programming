//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, d;
    cin>>n>>m>>d;

    vector<vector<int>>adj(n+1);
    vector<vector<int>>vis(n+1, vector<int>(n+1));
    vector<vector<int>>dis(n+1, vector<int>(n+1));

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        queue<int>q;
        q.push(i);
        vis[i][i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt: adj[cur]){
                if(!vis[i][nxt]){
                    vis[i][nxt] = true;
                    dis[i][nxt] = dis[i][cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }
    vector<int>path(n+1);

    for(int i=1;i<=n;i++){
        cin>>path[i];
    }
    while(d--){
        int x, y;
        cin>>x>>y;
        int temp = path[x];
        path[x] = path[y];
        path[y] = temp;

        for(int i=1;i<=n;i++){
            int cur = path[i];
            if(vis[cur][n]){
                cout<<i-1 + dis[cur][n]<<"\n";
                goto nxt;
            }
        }
        cout<<n<<"\n";

        nxt:;



    }



    




    return 0;
}