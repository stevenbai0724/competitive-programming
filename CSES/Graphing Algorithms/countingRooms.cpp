#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    vector<int>changeX{-1,1,0,0};
    vector<int>changeY{0,0,-1,1};
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    int count = 0;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    queue<int>q;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]!='#' && !vis[i][j]){
                q.push(i*2000+j);
                while(!q.empty()){
                    int x = q.front()/2000; int y = q.front()%2000;
                    q.pop();
                    for(int k = 0;k<4;k++){
                        int newx = x+changeX[k];
                        int newy = y+changeY[k];
                        if(newx>0 && newx<=n && newy>0 && newy<=m){
                            if(arr[newx][newy]!='#' && !vis[newx][newy]){
                                vis[newx][newy] = true;
                                q.push(newx*2000+newy);
                            }
                        }

                    }
                }
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}