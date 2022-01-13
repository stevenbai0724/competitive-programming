//https://dmoj.ca/problem/gfssoc1s3
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

    int n, m, t;
    cin>>n>>m>>t;

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<pair<int, int>>order;
    pair<int, int>OG;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];

            if(arr[i][j] == 'G')OG = {i,j};
            if(arr[i][j] == 'H')order.push_back({i,j});

        }
    }
    sort(order.begin(), order.end());

    vector<int>dx{-1,1,0,0}, dy{0,0,-1,1};

    pair<int, int>START = OG;

    int mn = 1e18;

    int tempNum = 0;
    bool tempGood = true;

    for(auto p: order){
        int nxtx = p.first;
        int nxty = p.second;
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));
        vector<vector<int>>dis(n+1, vector<int>(m+1));

        queue<pair<int, int>>q;

        vis[START.first][START.second] = true;
        q.push({START.first, START.second});

        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newx = curx + dx[k];
                int newy = cury + dy[k];
                if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                    if(!vis[newx][newy] && arr[newx][newy] != 'X'){
                        vis[newx][newy] = true;
                        dis[newx][newy] = dis[curx][cury] + 1;
                        q.push({newx, newy});
                    }
                }
            }
        }

        if(!vis[nxtx][nxty]){
            tempGood = false;
            break;
        }
        else{
            tempNum += dis[nxtx][nxty];
            START = {nxtx, nxty};
        }

    }

    if(tempGood)mn = tempNum;



    while(next_permutation(order.begin(), order.end())){
        bool good = true;
        int num = 0;
        START = OG;

        for(auto p: order){
            int nxtx = p.first;
            int nxty = p.second;
            vector<vector<bool>>vis(n+1, vector<bool>(m+1));
            vector<vector<int>>dis(n+1, vector<int>(m+1));

            queue<pair<int, int>>q;

            vis[START.first][START.second] = true;
            q.push({START.first, START.second});

            while(!q.empty()){
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newx = curx + dx[k];
                    int newy = cury + dy[k];
                    if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                        if(!vis[newx][newy] && arr[newx][newy] != 'X'){
                            vis[newx][newy] = true;
                            dis[newx][newy] = dis[curx][cury] + 1;
                            q.push({newx, newy});
                        }
                    }
                }
            }

            if(!vis[nxtx][nxty]){
                good = false;
                break;
            }
            else{
                num += dis[nxtx][nxty];
                START = {nxtx, nxty};
            }

        }

        if(good)mn = min(mn, num);

            
    }

    cout<<mn<<"\n";



    return 0;
}
