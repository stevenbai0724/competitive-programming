//https://dmoj.ca/problem/coci20c3p4
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

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }

    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    vector<int>dx{0,0,1,-1}, dy{-1,1,0,0};
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == '#' && !vis[i][j]){
                cnt++;
                vis[i][j] = true;
                for(int k=0;k<4;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x >= 1 && x <= n && y >= 1 && y <= m){
                        if(!vis[x][y] && arr[x][y] == '#'){
                            vis[x][y] = true;
                            while(true){
                                int newx = x + dx[k];
                                int newy = y + dy[k];
                                if(!(newx >= 1 && newx <= n && newy >= 1 && newy <= m))break;
                                if(vis[newx][newy] || arr[newx][newy] == '.')break;
                                vis[newx][newy] =  true;
                                x = newx;
                                y = newy;
                            }

                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<"\n";    

    return 0;
}
