//https://dmoj.ca/problem/coci20c4p5
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
    map<char, int>mp, mp2;

    mp['.'] = -1;
    mp['x'] = -1;
    mp['o'] = -1;

    mp['<'] = 0;
    mp['>'] = 1;
    mp['^'] = 2;
    mp['v'] = 3;

    mp2['>'] = 0;
    mp2['<'] = 1;
    mp2['v'] = 2;
    mp2['^'] = 3;
    mp2['.'] = -1;

    vector<vector<char>>arr(n+1, vector<char>(m+1));

    pair<int, int>START, END;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(arr[i][j] == 'o')START = {i,j};
            if(arr[i][j] == 'x')END = {i,j};
        }
    }

    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[i][j] = 1e18;
        }
    }
    dis[START.first][START.second] = 0;

    deque<pair<int, int>>q;

    vector<int>dx{0,0,-1,1};
    vector<int>dy{-1,1,0,0};

    set<pair<int, int>>finish;

    for(int i=0;i<4;i++){
        int newx = START.first + dx[i];
        int newy = START.second + dy[i];

        if(newx >= 1 && newx <=n && newy >= 1 && newy <=m ){
            dis[newx][newy] = 0;
            finish.insert({newx, newy});
            q.push_front({newx, newy});
        }
    }
    vis[START.first][START.second] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        char c = arr[x][y];
        q.pop_front();
        if(vis[x][y])continue;
        vis[x][y] = true;


        for(int k=0;k<4;k++){
            int newx = x + dx[k];
            int newy = y + dy[k];
            if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                if(mp[c] == k){
                    dis[newx][newy] = min(dis[newx][newy], dis[x][y]);
                    q.push_front({newx, newy});
                }
                else{
                    dis[newx][newy] = min(dis[newx][newy], dis[x][y] + 1);
                    q.push_back({newx, newy});
                }
                    
            }
        }
    }
    vector<vector<bool>>track(n+1, vector<bool>(m+1));
    track[END.first][END.second] = true;
    int cnt = 0;
    int curx = END.first;
    int cury = END.second;
    
    while(true){   
        if(finish.find({curx, cury}) != finish.end() || (curx == START.first && cury == START.second))break;
        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];

            if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                if(!track[newx][newy]){
                    
                    if(dis[newx][newy] == dis[curx][cury]){
        
                        if(mp2[arr[newx][newy]] == k){
                            
                            curx = newx;
                            cury = newy;
                            track[curx][cury] = true;
                            goto nxt;
                        }
                    }
                    else if(dis[newx][newy] +1 == dis[curx][cury]){
                        if(mp2[arr[newx][newy]] != k){
                            curx = newx;
                            cury = newy;
                            if(k == 0) arr[curx][cury] = '>';
                            else if(k == 1) arr[curx][cury] = '<';
                            else if(k == 2) arr[curx][cury] = 'v';
                            else arr[curx][cury] = '^';
                            track[curx][cury] = true;
                            cnt++;
                            goto nxt;
                        }
                    }

                }
            }
        }
        assert(false);
        nxt:;
    }

    
    cout<<cnt<<"\n";

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }




    return 0;
}
