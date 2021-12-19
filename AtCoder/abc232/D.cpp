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

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    int mx = 0;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }

    }
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    vector<vector<int>>dis(n+1, vector<int>(m+1));
    queue<pair<int, int>>q;

    vis[1][1] = true;

    q.push({1,1});

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        int a = curx;
        int b = cury + 1;
        int c = curx + 1;
        int d = cury;

        if(a <= n && b <= m){
            if(!vis[a][b] && arr[a][b] == '.'){
                vis[a][b] = true;
                dis[a][b] = dis[curx][cury] + 1;
                mx = max(dis[a][b], mx);
                q.push({a,b});
            }
        }
        if(c <= n && d <= m){
            if(!vis[c][d] && arr[c][d] == '.'){
                vis[c][d] = true;
                dis[c][d] = dis[curx][cury] + 1;
                mx = max(dis[c][d], mx);
                q.push({c,d});
            }
        }
    }

    cout<<mx+1<<"\n";




    return 0;
}