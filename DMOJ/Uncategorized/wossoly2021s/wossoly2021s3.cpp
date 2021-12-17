//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; 
    cin>>n>>m;
    map<char, int>mp;
    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<vector<pair<int, int>>>>adj(n+1, vector<vector<pair<int, int>>>(m+1));

    vector<pair<char, pair<int, int>>>order;
    
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];

            if(arr[i][j] >= '0' && arr[i][j] <= '4')order.push_back({arr[i][j], {i, j}});
            if(arr[i][j] >= 'a' && arr[i][j] <='z')mp[arr[i][j]] = i*((int)1e7) + j;

        }
    }
    sort(order.begin(), order.end());
    vector<int>dx{0,0,-1,1};
    vector<int>dy{-1,1,0,0};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int newx = i + dx[k];
                int newy = j + dy[k];
                if(newx >= 1 && newy >= 1 && newx <= n && newy <=m){
                    char c = arr[newx][newy];
                    if(c == '.' || (c >= '0' && c <= '4')){
                        adj[i][j].push_back({newx, newy});
                    }
                    if(c >= 'A' && c <= 'Z'){
                        adj[i][j].push_back({mp[c+32]/10000000, mp[c+32]%10000000});
                    }
                }
            }
            
        }
    }
    int cnt = 0;

    for(int i=0;i<=3;i++){
        auto p = order[i];
        vector<vector<int>>dis(n+1, vector<int>(m+1));
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));

        queue<pair<int, int>>q;

        q.push({p.second.first, p.second.second});
        vis[p.second.first][p.second.second] = true;

        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(auto nxt: adj[curx][cury]){
                int newx = nxt.first;
                int newy = nxt.second;
                if(!vis[newx][newy]){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[curx][cury] + 1;
                    q.push({newx, newy});
                }
            }
        }
        int desX = order[i+1].second.first;
        int desY = order[i+1].second.second;

        if(!vis[desX][desY]){
            cout<<-1<<"\n";
            return 0;
        }
        cnt += dis[desX][desY];

    }
    cout<<cnt<<"\n";


    return 0;
}

    