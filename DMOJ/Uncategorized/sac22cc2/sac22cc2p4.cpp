//https://dmoj.ca/problem/sac22cc2p4
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

    deque<pair<int, int>>q;

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<int>>dis(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            dis[i][j] = 1e18;
        }
    }
    dis[1][1] = (arr[1][1] == 'C');

    q.push_back({1,1});

    vector<int>dx{0,0,-1,1}, dy{1,-1,0,0};

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop_front();
        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];

            if(newx >= 1 && newy >= 1 && newx <=n && newy <=m){
                int w = arr[newx][newy] == 'C';
                if(dis[curx][cury] + w < dis[newx][newy]){
                    dis[newx][newy] = dis[curx][cury] + w;
                    if(w == 0){
                        q.push_front({newx, newy});
                    }
                    else{
                        q.push_back({newx, newy});
                    }
                }
            }
        }
    }
    cout<<dis[n][m]<<"\n";

    return 0;
}