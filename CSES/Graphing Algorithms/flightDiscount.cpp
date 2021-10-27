//https://cses.fi/problemset/task/1195
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>>adj1(n+1), adj2(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    vector<int>dis1(n+1, 1e18);
    vector<int>dis2(n+1, 1e18);
    dis1[1] = 0;
    dis2[n] = 0;
    vector<pair<int, pair<int, int>>>edge;
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj1[x].push_back({w,y});
        adj2[y].push_back({w,x});
        edge.push_back({w,{x,y}});
    }

    q.push({0,1});

    while(!q.empty()){
        int y = q.top().second;
        int w = q.top().first;
        q.pop();
        if(dis1[y]<w)continue;
        for(auto nxt: adj1[y]){
            int newy = nxt.second;
            int neww = nxt.first;
            if(dis1[y]+neww < dis1[newy]){
                dis1[newy] = dis1[y] + neww;
                q.push({dis1[newy], newy});
            }
        }
    }
    q.push({0,n});

    while(!q.empty()){
        int y = q.top().second;
        int w = q.top().first;
        q.pop();
        if(dis2[y]<w)continue;
        for(auto nxt: adj2[y]){
            int newy = nxt.second;
            int neww = nxt.first;
            if(dis2[y]+neww < dis2[newy]){
                dis2[newy] = dis2[y] + neww;
                q.push({dis2[newy], newy});
            }
        }
    }

    int ans = 1e18;

    for(auto e: edge){
        int w = e.first;
        int x = e.second.first;
        int y = e.second.second;

        ans = min(ans, dis1[x] + w/2 + dis2[y]);
    }
    cout<<ans<<"\n";



    return 0;
}