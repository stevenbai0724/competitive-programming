//https://dmoj.ca/problem/ucrpc21d
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

    vector<int>dx{1,-1,0,0}, dy{0,0,-1,1};

    vector<int>ans;

    int n, m;
    cin>>n>>m;
    n*=2;
    m*=2;
    n++;
    m++;

    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
        }
    }
    
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j] == '.'){
                if(!vis[i][j]){
                    vis[i][j] = true;
                    queue<pair<int, int>>q;
                    q.push({i,j});
                    int cnt = 0;

                    
                    while(!q.empty()){
                        int curx = q.front().first;
                        int cury = q.front().second;
                        if(curx%2 == 0 && cury%2 == 0)cnt++;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int newx = curx + dx[k];
                            int newy = cury + dy[k];
                            if(newx >= 1 && newx <= n && newy >= 1 && newy <= m){
                                if(!vis[newx][newy] && arr[newx][newy] == '.'){
                                    vis[newx][newy] = true;
                                    q.push({newx, newy});
                                }
                            }
                        }
                    }

                    ans.push_back(cnt);

                }
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
