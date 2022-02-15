//
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
int dis(int a, int b, int c, int d){
    return abs(a-b) + abs(c-d);
}
struct edge{
    int x, y, c;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>>arr(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    if(n <= 50 && m <= 50){
        vector<pair<int, int>>zero;
        vector<edge>source;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == 0)zero.push_back({i,j});
                else source.push_back({i,j,arr[i][j]});
            }
        }
        for(auto pp: zero){
            int x = pp.first;
            int y = pp.second;
            int mnDis = 1e18;
            int colour = 0;
            for(auto nxt: source){
                int newx = nxt.x;
                int newy = nxt.y;
                int c = nxt.c;

                int dist = dis(x, newx, y, newy);
                if(dist <= k){
                    if(dist < mnDis){
                        colour = c;
                        mnDis = dist;
                    }
                    else if(dist == mnDis){
                        colour = min(colour, c);
                    }
                }
            }

            if(mnDis!=1e18){
                arr[x][y] = colour;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        vector<int>dx{0,0,-1,1}, dy{-1,1,0,0};

        vector<vector<int>>vis(n+1, vector<int>(m+1)), dis(n+1, vector<int>(m+1)), colour(n+1, vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == 0)colour[i][j] = 1e18;
                else colour[i][j] = arr[i][j];
            }
        }

        queue<pair<int, int>>q;
        vector<vector<bool>>inq(n+1, vector<bool>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] != 0){
                    q.push({i,j});
                    vis[i][j] = true;
                    inq[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            
            q.pop();
            if(dis[curx][cury] == k)continue;
            
            for(int l=0;l<4;l++){
                int newx = dx[l] + curx;
                int newy = dy[l] + cury;
                if(newx >=1 && newx <=n && newy >= 1 && newy <= m){
                    
                    if(!vis[newx][newy]){
                        vis[newx][newy] = true;
                        colour[newx][newy] = colour[curx][cury];
                        dis[newx][newy] = dis[curx][cury] + 1;
                        q.push({newx, newy});
                        inq[newx][newy] = true;
                    }
                    else if(dis[curx][cury] + 1 == dis[newx][newy]){
                        colour[newx][newy] = min(colour[newx][newy], colour[curx][cury]);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(colour[i][j] == 1e18)cout<<0<<" ";
                else cout<<colour[i][j]<<" ";
            }
            cout<<"\n";
        }
    }


    return 0;
}
