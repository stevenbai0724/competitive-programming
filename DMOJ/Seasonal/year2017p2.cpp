//https://dmoj.ca/problem/year2017p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int mxn = 2e5+1;
    map<int, int>mpX, mpY;

    int startX, startY;
    cin>>startX>>startY;

    mpX[startX] = 1;
    mpY[startY] = 1;

    vector<vector<pair<int, int>>>adjX(mxn+1), adjY(mxn+1); //adjX will be points with same X coordinates {y, id}


    adjX[1].push_back({startY, 1});
    adjY[1].push_back({startX, 1});


    int o; cin>>o;
    int curX = 2;
    int curY = 2;
    for(int i=2;i<=o+1;i++){
        int x, y;
        cin>>x>>y;
        if(mpX[x] == 0){
            mpX[x] = curX;
            curX++;
        }
        if(mpY[y] == 0){
            mpY[y] = curY;
            curY++;
        }
        adjX[mpX[x]].push_back({y, i});
        adjY[mpY[y]].push_back({x, i});

    }
    int e; cin>>e;

    for(int i=2+o;i<=1+o+e;i++){
        int x, y;
        cin>>x>>y;
        if(mpX[x] == 0){
            mpX[x] = curX;
            curX++;
        }
        if(mpY[y] == 0){
            mpY[y] = curY;
            curY++;
        }
        adjX[mpX[x]].push_back({y, i});
        adjY[mpY[y]].push_back({x, i});
    }

    for(int i=1;i<=mxn;i++){
        sort(adjX[i].begin(), adjX[i].end());
        sort(adjY[i].begin(), adjY[i].end());
    }
    queue<int>q;
    vector<int>dis(mxn+1);
    vector<bool>vis(mxn+1);
    vector<vector<int>>adj(mxn+1);

    for(int i=1;i<=mxn;i++){
        if(adjX[i].size() >= 2){
            for(int j=0;j<=adjX[i].size()-2;j++){
                int ax = adjX[i][j].second;
                int ay = adjX[i][j+1].second;
                adj[ax].push_back(ay);
                adj[ay].push_back(ax);
            }   
        }
        if(adjY[i].size() >= 2){
            for(int j=0;j<=adjY[i].size()-2;j++){
                int x = adjY[i][j].second;
                int y = adjY[i][j+1].second;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
    }

    vis[1] = true;
    q.push(1);

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
    int mn = 1e18;  

    for(int i=2+o;i<=1+o+e;i++){
        if(vis[i])mn = min(mn, dis[i]);
    }
    cout<<(mn == 1e18 ? -1 : mn-1)<<"\n";

    return 0;
}