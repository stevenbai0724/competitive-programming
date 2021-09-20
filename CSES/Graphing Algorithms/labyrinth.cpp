//https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<int>X{1,-1,0,0};
    vector<int>Y{0,0,1,-1};
    pair<int, int>start, end;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(s[j-1]=='A') start = {i,j};
            else if(s[j-1]=='B')end = {i,j};
        }
    }
    queue<pair<int, int>>q;
    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    vector<vector<bool>>vis2(n+1,vector<bool>(m+1));
    vis[start.first][start.second] = true;
    q.push(start);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];

            if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                if(!vis[newx][newy] && arr[newx][newy]!='#'){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[x][y]+1;
                    q.push({newx, newy});
                }
            }
        }
    }
    if(!vis[end.first][end.second]){
        cout<<"NO";
        return 0;
    }

    int cur = dis[end.first][end.second];
    string ans = "";
    vector<char>vec;
    cout<<"YES"<<"\n"<<cur<<"\n";

    q.push(end);

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];


            if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                if(!vis2[newx][newy] && arr[newx][newy]!='#' && dis[newx][newy]==cur-1){
                                
                    vis2[newx][newy] = true;
                    q.push({newx, newy});
                    if(i==0)vec.push_back('U');
                    if(i==1)vec.push_back('D');
                    if(i==2)vec.push_back('L');
                    if(i==3)vec.push_back('R');
                    cur--;
                    continue;
            
                }
            }
        }
    
    }

    for(int i=vec.size()-1;i>=0;i--){
        ans+=vec[i];
    }

    cout<<ans;
    


    return 0;
}