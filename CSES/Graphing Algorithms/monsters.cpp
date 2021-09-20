//https://cses.fi/problemset/task/1194
//TLE, 18 out of 21 points
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
 
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<pair<int, int>>mon;
    vector<vector<int>>mDis(n+1, vector<int>(m+1));
    vector<vector<pair<int, int>>>p(n+1, vector<pair<int, int>>(m+1)); //parent array
    string ans = "";
    queue<pair<int, int>>q;
    vector<int>X{1,-1,0,0};
    vector<int>Y{0,0,1,-1};
    pair<int, int>start;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            mDis[i][j] = 1e18;
            arr[i][j] = s[j-1];
            if(s[j-1]=='M')mon.push_back({i,j});
            else if(s[j-1]=='A')start = {i,j};
        }
    }
    for(auto x:mon){
        vector<vector<int>>dis(n+1, vector<int>(m+1));
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));
 
        q.push(x);  
        vis[x.first][x.second] = true;
        mDis[x.first][x.second] = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+X[i];
                int newy = y+Y[i];
                if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                    if(arr[newx][newy]!='#' && !vis[newx][newy]){
                        vis[newx][newy] = true;
                        q.push({newx, newy});
                        dis[newx][newy] = dis[x][y] +1;
                        mDis[newx][newy] = min(mDis[newx][newy], dis[newx][newy]);
                    }
                }
            }
        }
    }
    vector<vector<int>>aDis(n+1, vector<int>(m+1));
    vector<vector<bool>>aVis(n+1,vector<bool>(m+1));
 
    q.push(start);
    aVis[start.first][start.second] =true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = x+X[i];
            int newy = y+Y[i];
            if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                if(arr[newx][newy]!='#' && !aVis[newx][newy] && aDis[x][y]+1<mDis[newx][newy]){
                    aDis[newx][newy] = aDis[x][y]+1;
                    aVis[newx][newy] = true;
                    p[newx][newy] = {x,y};
                    q.push({newx, newy});
                }
            }
        }
    }
    bool no = true;
    pair<int, int>end;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 || i==n || j==1 || j==m){
                if(aVis[i][j]){
                    no = false;
                    end = {i,j};
 
                }
            }
            if(!no)break;
        }
        if(!no)break;
    }   
    if(no){
        cout<<"NO";
        return 0;
    }
    int curx = end.first;
    int cury = end.second;
    vector<char>vec;
 
 
    while(aDis[curx][cury]!=0){
        int newx = p[curx][cury].first;
        int newy = p[curx][cury].second;
 
        if(newx<curx)vec.push_back('D');
        if(newx>curx)vec.push_back('U');
        if(newy<cury)vec.push_back('R');
        if(newy>cury)vec.push_back('L');
        
        curx = newx;
        cury = newy;
    }
 
 
    reverse(vec.begin(), vec.end());
    for(auto x:vec){
        ans+=x;
    }
    cout<<"YES\n"<<vec.size()<<"\n"<<ans;
    
 
 
 
    return 0;
}
