//http://www.usaco.org/index.php?page=viewproblem2&cpid=920
//USACO 2019 February Contest Silver P3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin>>n>>m;
    vector<pair<char, pair<int, int>>>edge;
    vector<vector<pair<char, int>>>adj(n+1);
    for(int i=1;i<=m;i++){
        char c; cin>>c;
        int x, y;
        cin>>x>>y;
        edge.push_back({c,{x,y}});
        adj[x].push_back({c,y});
        adj[y].push_back({c,x});
    }
    int cnt = 0;
    vector<bool>vis(n+1);
    vector<bool>colour(n+1);

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        cnt++;
        vis[i] = true;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto e: adj[cur]){
                if(vis[e.second])continue;
                vis[e.second] = true;
                if(e.first == 'S'){
                    colour[e.second] = colour[cur];
                }
                else colour[e.second] = !colour[cur];
                q.push(e.second);
            }
        }

    }

    bool good = true;
    for(auto e: edge){
        if(e.first == 'S' && colour[e.second.first] != colour[e.second.second])good = false;
        if(e.first == 'D' && colour[e.second.first] == colour[e.second.second]) good = false;
    }
    if(!good)cout<<0<<"\n";
    else{
        cout<<1;
        for(int i=1;i<=cnt;i++)cout<<0;
        cout<<"\n";
    }



    return 0;
}