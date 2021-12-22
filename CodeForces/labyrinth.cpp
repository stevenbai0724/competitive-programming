//
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
    int r, c;
    cin>>r>>c;
    int x, y;
    cin>>x>>y;

    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }

    vector<vector<int>>dis(n+1, vector<int>(m+1));
    vector<vector<pair<int, int>>>use(n+1, vector<pair<int, int>>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){  
            dis[i][j] = 1e18;
        }
    }
    dis[r][c] = 0;

    deque<pair<int, int>>q;

    vector<int>dx{0,0,-1,1}, dy{-1,1,0,0};

    q.push_front({r,c});

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop_front();
        for(int k=0;k<4;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];
            int w = (k==0);
            if(newx >=1 && newy >= 1 && newx <=n && newy <=m){
                if(arr[newx][newy] == '.' && dis[curx][cury] + w < dis[newx][newy]){

                    use[newx][newy].first = use[curx][cury].first;
                    use[newx][newy].second = use[curx][cury].second;

                    dis[newx][newy] = w + dis[curx][cury];

                    if(k == 0)use[newx][newy].first++;
                    if(k == 1)use[newx][newy].second++;

                    if(k == 0)q.push_back({newx, newy});
                    else q.push_front({newx, newy});
                }
            }
        }

    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(use[i][j].first <= x && use[i][j].second <= y && dis[i][j]!=1e18)cnt++;
        }

    }
    cout<<cnt<<"\n";



    return 0;
}