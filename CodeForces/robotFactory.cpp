//https://codeforces.com/problemset/problem/1600/J
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

    vector<int>dx{-1,0,1,0}, dy{0,1,0,-1};

    vector<vector<vector<bool>>>wall(n+2, vector<vector<bool>>(m+2));

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            wall[i][j].resize(4);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; cin>>x;
            if(x&8){
                wall[i][j][0] = true;
                wall[i-1][j][2] = true;
            }
            if(x&4){
                wall[i][j][1] = true;
                wall[i][j+1][3] = true;
            }
            if(x&2){
                wall[i][j][2] = true;
                wall[i+1][j][0] = true;
            }
            if(x&1){
                wall[i][j][3] = true;
                wall[i][j-1][1] = true;
            }
        }
    }
    vector<int>ans;

    
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j])continue;
            int cnt = 1;

            queue<pair<int, int>>q;
            q.push({i,j});

            vis[i][j] = true;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newx = x + dx[k];
                    int newy = y + dy[k];

                    if(wall[x][y][k])continue;

                    if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                        if(!vis[newx][newy]){
                            vis[newx][newy] = true;
                            cnt ++ ;
                            q.push({newx, newy});
                        }
                    }
                }
            }
            ans.push_back(cnt);

        }
    }
    sort(ans.begin(), ans.end(), greater<int>());

    for(auto x: ans)cout<<x<<" ";
    cout<<"\n";




    return 0;
}