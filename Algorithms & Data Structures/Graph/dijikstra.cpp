//dijikstra's shortest path algorithm, (n+m)log(n+m) 
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
    vector<vector<pair<int, int>>>adj(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;



    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    vector<int>dis(n+1, 1e18);

    dis[1] = 0;

    q.push({0,1});

    while(!q.empty()){
        int w = q.top().first;
        int y = q.top().second;
        q.pop();
        if(dis[y]<w)continue;

        for(auto nxt: adj[y]){
            int neww = nxt.first;
            int newy = nxt.second;
            if(dis[y]+neww < dis[newy]){
                dis[newy] = dis[y] + neww;
                q.push({dis[newy], newy});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[i] == 1e18)cout<<-1<<"\n";
        else cout<<dis[i]<<"\n";
    }



    return 0;
}