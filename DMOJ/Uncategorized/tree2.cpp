//https://dmoj.ca/problem/tree2
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
    vector<vector<char>>arr(n+1, vector<char>(m+1));

    int big = 0;
    int small = 1e18;
    pair<int, int>START, END;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j] >= '0' && arr[i][j] <= '9'){
                big = max(big, (int)(arr[i][j] - '0'));
                small = min(small, (int)(arr[i][j] - '0'));
            }
            if(arr[i][j] == 'X')START = {i,j};
        }
    }

    int mn = 1e18;
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] - '0' == big){
                int x = abs(i - START.first);
                int y = abs(j - START.second);
                assert(x*x + y*y != mn);
                if(x*x + y*y < mn){
                    mn = x * x + y * y;
                    END = {i,j};
                }
            }
        }
    }
    deque<pair<int, int>>q;
    vector<int>dx{-1,1,0,0}, dy{0,0,-1,1};
    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    vis[START.first][START.second] = true;
    q.push_back({START});

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop_front();

        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];
            if(newx >= 1 && newx <= n && newy >= 1 && newy <=m){
                if(!vis[newx][newy]){
                    if(END == (pair<int, int>){newx, newy}){
                        assert((int)(arr[newx][newy] - '0') == big);
                        cout<<dis[curx][cury]<<"\n";
                        return 0;
                    }
                    if(arr[newx][newy] == '.'){
                        dis[newx][newy] = dis[curx][cury];
                        vis[newx][newy] = true;
                        q.push_front({newx, newy});
                    }
                    if((int)(arr[newx][newy] - '0') == small){
                        dis[newx][newy] = dis[curx][cury] + 1;
                        vis[newx][newy] = true;
                        q.push_back({newx, newy});                  
                    }
                }
            }
        }

    }


    return 0;
}
