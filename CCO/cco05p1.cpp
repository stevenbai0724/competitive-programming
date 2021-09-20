//
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<int>cX{-1,1,0,0};
vector<int>cY{0,0,-1,1};
int c = 1e9;
vector<vector<bool>>vis;
vector<vector<int>>arr;
bool bfs(vector<int>v){
    
    for(int i=1;i<=m;i++){
        fill(vis.begin(), vis.end(), vector<bool>(m+1, false));
        queue<int>q;
        q.push(c + i);
        vis[1][i] = true;
        while(!q.empty()){
            int x = q.front()/c;
            int y = q.front()%c;
            q.pop();
            for(int j=0;j<4;j++){
                int newx = x+cX[j];
                int newy = y+cY[j];
                if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                    if((arr[newx][newy]==v[0] || arr[newx][newy]==v[1] || arr[newx][newy]==v[2]) && !vis[newx][newy]){
                        vis[newx][newy] = true;
                        q.push(newx*c + newy);
                        if(newx==n)return true;
                        
                    }
                }
            }
        }
        
    }
    return false;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin>>m>>n;
    
    vis.resize(n+1);
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        vis[i].resize(m+1);
        arr[i].resize(m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int  i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                
                if(bfs({i,j,k})){
                    cout<<i<<" "<<j<<" "<<k;
                    return 0;
                }
                

            }
        }
    }
    cout<<"-1 -1 -1";

    return 0;
}