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

    int n, k;
    cin>>n>>k;

    vector<vector<pair<int ,int>>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }   
    int mn = 1e18;
    vector<int>ans;
    for(int i=1;i<(1<<n);i++){
        vector<int>park;

        for(int j=1;j<=n;j++){
            if(((int)1 << (j-1))&i){
                park.push_back(j);
            }
        }
        
        if(park.size() == k){
            vector<int>close(n+1, 1e18);
            
            for(int START: park){
                close[START] = 0;
                int mx = 0;
                queue<int>q;
                vector<bool>vis(n+1);
                vector<int>dis(n+1);
                q.push(START);
                vis[START] = true;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(auto pi : adj[cur]){
                        int nxt = pi.second;
                        int w = pi.first;
                        if(!vis[nxt]){
                            vis[nxt] = true;
                            dis[nxt] = dis[cur] + w;
                            q.push(nxt);
                            close[nxt] = min(close[nxt], dis[nxt]);
                        }
                    }
                }
                
            }
            int mx = 0;
            for(int i=1;i<=n;i++){
                mx = max(mx, close[i]);
            }
            if(mx < mn){
                ans = park;
                mn = mx;
            }

        }
    }

    cout<<mn<<"\n";

    for(int x: ans)cout<<x<<" ";
    cout<<"\n";

    return 0;
}
