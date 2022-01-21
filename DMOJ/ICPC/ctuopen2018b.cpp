//https://dmoj.ca/problem/ctuopen2018b
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>dx{-1,-1,-1,0,0,1,1,1};
    vector<int>dy{-1,0,1,1,-1,-1,0,1};

    queue<pair<int, int>>q;
    vector<vector<int>>dis(5001, vector<int>(5001));
    vector<vector<bool>>vis(5001, vector<bool>(5001));

    while(n--){
        int x, y;
        cin>>x>>y;
        dis[x][y] = 0;
        q.push({x,y});
        vis[x][y] = true;
    }

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(newx >= 0 && newx <=5000 && newy>=0 && newy <= 5000){
                if(!vis[newx][newy]){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[curx][cury] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }

    while(k--){
        int x, y;
        cin>>x>>y;
        cout<<dis[x][y]<<"\n";
    }



    return 0;
}
