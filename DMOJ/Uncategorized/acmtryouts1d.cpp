//https://dmoj.ca/problem/acmtryouts1d
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;  
    vector<int>dx{0,0,-1,1}, dy{-1,1,0,0};
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>>arr(n+1, vector<char>(m+1));
        pair<int, int>START, END;
        vector<pair<int, int>>grass;


        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                arr[i][j] = s[j-1];
                if(arr[i][j]=='F')START = {i,j};
                if(arr[i][j]=='H')END = {i,j};
                if(arr[i][j]=='G')grass.push_back({i,j});
            }
        }
        int ans = 1e18;

        int len = grass.size();

        vector<vector<pair<int, int>>>block;
        block.push_back({});
        for(int i=0;i<len;i++){
            int iX = grass[i].first;
            int iY = grass[i].second;
            block.push_back({{iX, iY}});

            for(int j=i+1;j<len;j++){
                int jX = grass[j].first;
                int jY = grass[j].second;
                block.push_back({{iX, iY}, {jX, jY}});

                for(int k=j+1;k<len;k++){
                    int kX = grass[k].first;
                    int kY = grass[k].second;
                    block.push_back({{iX, iY}, {jX, jY}, {kX, kY}});
                    
                    for(int l=k+1;l<len;l++){
                        int lX = grass[l].first;
                        int lY = grass[l].second;
                        block.push_back({{iX, iY}, {jX, jY}, {kX, kY}, {lX, lY}});
                    }
                }
            }
        }

        for(auto v: block){
            vector<vector<bool>>NO(n+1, vector<bool>(m+1));

            for(auto p: v){
                NO[p.first][p.second] = true;
            }


            vector<vector<bool>>vis(n+1, vector<bool>(m+1));

            queue<pair<int, int>>q;
            q.push(START);
            vis[START.first][START.second] = true;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newx = x+dx[k];
                    int newy = y+dy[k];

                    if(newx>=1 && newx<=n && newy>=1 && newy<=m){
                        if(!vis[newx][newy] && arr[newx][newy]!='T' && !NO[newx][newy]){
                            vis[newx][newy] = true;
                            q.push({newx, newy});
                        }
                    }   
                }
            }
            if(!vis[END.first][END.second])ans = min(ans, (int)v.size());


        }

        cout<<ans<<"\n";




        

    }


    return 0;
}