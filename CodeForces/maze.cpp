//https://codeforces.com/problemset/problem/377/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

struct edge{
    int dis, x, y;
};
bool comp(edge a, edge b){
    return a.dis > b.dis;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<edge>order;
    pair<int, int>START;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(arr[i][j] == '.')START = {i,j};
        }
    }
    queue<pair<int, int>>q;
    vector<int>dx{0,0,-1,1}, dy{1,-1,0,0};
    vector<vector<int>>vis(n+1, vector<int>(m+1)), dis(n+1, vector<int>(m+1));

    q.push(START);
    order.push_back({0,START.first, START.second});
    vis[START.first][START.second] = true;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];
            if(newx >= 1 && newy >= 1 && newx <= n && newy <=m){
                if(!vis[newx][newy] && arr[newx][newy] == '.'){
                    vis[newx][newy] = true;
                    dis[newx][newy] = dis[curx][cury] + 1;
                    q.push({newx, newy});
                    order.push_back({dis[newx][newy], newx, newy});
                }
            }
        }
    }
    sort(order.begin(), order.end(), comp);

    for(int i=0;i<k;i++){
        arr[order[i].x][order[i].y] = 'X';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }


    return 0;
}