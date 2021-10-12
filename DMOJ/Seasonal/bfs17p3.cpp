//https://dmoj.ca/problem/bfs17p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

struct edge{
    int x, y, w;

};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int ans1 = 1e9;
    int ans2 = 1e9;
    if(true){
        int baller, starter;
        int mx = 0;
        vector<edge>arr(n+1);

        for(int i=1;i<=n;i++){
            int x, y, w;
            cin>>x>>y>>w;
            if(y>mx){
                mx = y;
                starter = i;
            }
            if(w==9001)baller = i;

            arr[i] = {x,y,w};
        }

        vector<int>dis(n+1);
        vector<int>vis(n+1);
        vector<vector<int>>adj(n+1);

        for(int i=1;i<=n;i++){
            if(i==baller)continue;
            int x = arr[i].x;
            int y = arr[i].y;
            int w = arr[i].w;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                int newx = arr[j].x;
                int newy = arr[j].y;

                int X = abs(x-newx);
                int Y = abs(y-newy);
                if(sqrt((X*X) + (Y*Y))<=w){
                    adj[i].push_back(j);
                }
            }
        }

        vis[starter] = true;
        queue<int>q;
        q.push(starter);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        
        if(vis[baller])ans1 = dis[baller];
    }
    if(true){
        int baller, starter;
        int mx = 0;
        vector<edge>arr(m+1);

        for(int i=1;i<=m;i++){
            int x, y, w;
            cin>>x>>y>>w;
            if(y>mx){
                mx = y;
                starter = i;
            }
            if(w==9001)baller = i;

            arr[i] = {x,y,w};
        }

        vector<int>dis(m+1);
        vector<int>vis(m+1);
        vector<vector<int>>adj(m+1);

        for(int i=1;i<=m;i++){
            if(i==baller)continue;
            int x = arr[i].x;
            int y = arr[i].y;
            int w = arr[i].w;
            for(int j=1;j<=m;j++){
                if(i==j)continue;
                int newx = arr[j].x;
                int newy = arr[j].y;

                int X = abs(x-newx);
                int Y = abs(y-newy);
                if(sqrt((X*X) + (Y*Y))<=w){
                    adj[i].push_back(j);
                }
            }
        }

        vis[starter] = true;
        queue<int>q;
        q.push(starter);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        if(vis[baller])ans2 = dis[baller];
    }
    cout<<((ans1<ans2) ? "We are the champions!\n" : (ans1>ans2 ? ":'(\n" : "SUDDEN DEATH\n"));







    return 0;
}