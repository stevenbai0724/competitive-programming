//https://codeforces.com/contest/1365/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<pair<int, int>>bad;
        int good = 0;
        vector<vector<char>>arr(n+3, vector<char>(m+3));
        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                arr[i][j] = s[j-1];
                if(arr[i][j]=='G')good ++ ;
                if(arr[i][j]=='B')bad.push_back({i,j});
            }
        }
        if(good == 0){
            cout<<"Yes\n";
            continue;
        }
        vector<int>dx{-1,1,0,0}, dy{0,0,-1,1};
        queue<pair<int, int>>q;
        int cnt = 0;
        vector<vector<int>>vis(n+3, vector<int>(m+3));
        for(auto p: bad){
            int x = p.first;
            int y = p.second;
            for(int k=0;k<4;k++){
                int newx = x + dx[k];
                int newy = y + dy[k];
                if(arr[newx][newy] == 'G'){
                    cout<<"No\n";
                    goto nxt;
                }
                arr[newx][newy] = '#';
            }
        }
        if(arr[n][m] == '#'){
            cout<<"No\n";
            
            goto nxt;
        }
        q.push({n,m});
        vis[n][m] = true;
        
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newx = curx + dx[k];
                int newy = cury + dy[k];
                if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                    if(!vis[newx][newy] && arr[newx][newy] != '#'){
                        vis[newx][newy] = true;
                        if(arr[newx][newy] == 'G')cnt ++ ;
                        q.push({newx, newy});
                    }
                }
            }
        }
        if(good != cnt)cout<<"No\n";
        else cout<<"Yes\n";


        nxt:;

        
    }

    return 0;
}