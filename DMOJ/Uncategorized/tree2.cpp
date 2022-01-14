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
struct edge{
    int d, x, y;
};
class Compare{
    public: 
        bool operator() (edge a, edge b){
            return a.d > b.d;
        }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));

    int MX = 0;
    pair<int, int>START;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'X')START = {i,j};
            if(arr[i][j] >= '0' && arr[i][j] <= '9'){
                MX = max(MX, (int)(arr[i][j] - '0'));
            }
        }
    }

    int MN = 1e18;
    pair<int, int>END;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] - '0' == MX){
                int x = abs(i - START.first);
                int y = abs(j - START.second);
                if(x*x + y*y < MN){
                    MN = x*x + y*y;
                    END = {i,j};
                }
            }
        }
    }
    arr[END.first][END.second] = '.';
    
    vector<vector<pair<int, int>>>dis(n+1, vector<pair<int, int>>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[i][j] = {1e18, 1e18};
        }
    }
    dis[START.first][START.second] = {0,0};

    priority_queue<edge, vector<edge>, Compare>q;

    vector<int>dx{-1,1,0,0}, dy{0,0,-1,1};
    q.push({0,START.first, START.second});

    while(!q.empty()){
        edge e = q.top();
        int curx = e.x;
        int cury = e.y;

        q.pop();

        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];
            if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                if(arr[newx][newy] == '.'){
                    if(dis[newx][newy].first > dis[curx][cury].first){
                        dis[newx][newy] = dis[curx][cury];
                        q.push({dis[newx][newy].first, newx, newy});
                    }
                    else if (dis[newx][newy].first == dis[curx][cury].first && dis[newx][newy].second > dis[curx][cury].second){
                        dis[newx][newy] = dis[curx][cury];
                        q.push({dis[newx][newy].first, newx, newy});
                    }
                    
                }
                if(arr[newx][newy] >= '0' && arr[newx][newy] <= '9'){
                    int len = (int)(arr[newx][newy] - '0');
                    if(dis[newx][newy].first > dis[curx][cury].first + len ){
                        dis[newx][newy] = {dis[curx][cury].first + len, dis[curx][cury].second + 1}; //new dis = old dis + edge, new count = old count + 1
                        q.push({dis[newx][newy].first, newx, newy});
                    }
                    else if(dis[newx][newy].first == dis[curx][cury].first + len && dis[newx][newy].second > dis[curx][cury].second + 1){
                        dis[newx][newy] = dis[curx][cury];
                        dis[newx][newy].second++;
                        q.push({dis[newx][newy].first, newx, newy});
                    }
                }

            }
        }
    }

    cout<<dis[END.first][END.second].second<<"\n";



    return 0;
}
