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

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<bool>>arr(n+2, vector<bool>(m+2));

    vector<int>dx{0,0,-1,1}, dy{1,-1,0,0};

    for(int i=1;i<=k;i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = true;
    }
    queue<pair<int, int>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!arr[i][j]){
                int cnt = arr[i-1][j] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j];
                if(cnt >=2 ){
                    arr[i][j] = true;
                    q.push({i,j});
                }
            }
        }
    }
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();


        for(int k=0;k<4;k++){
            int newx = i+dx[k];
            int newy = j+dy[k];
            if(arr[newx][newy])continue;
            if(newx < 1 || newy < 1 || newx > n || newy > m)continue;
            int cnt = arr[newx-1][newy] + arr[newx][newy-1] + arr[newx][newy+1] + arr[newx+1][newy];
            if(cnt >= 2){
                arr[newx][newy] = true;
                q.push({newx, newy});
            }
        }

    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans += arr[i][j];
        }
    }

    cout<<ans<<"\n";

    return 0;
}