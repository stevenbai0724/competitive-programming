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

    if(n <= 1000){
        vector<vector<pair<int, int>>>adj(n+1);

        for(int i=1;i<n;i++){
            int x, y, w;
            cin>>x>>y>>w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        int ans = 0;

        for(int START = 1; START <=n; START++){
            vector<bool>vis(n+1);
            vector<int>dis(n+1);
            vector<int>mx(n+1);
            queue<int>q;
            vis[START] = true;
            q.push(START);
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(auto p: adj[cur]){
                    int nxt = p.first;
                    int w = p.second;
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        dis[nxt] = dis[cur] + 1;
                        mx[nxt] = max(mx[cur], w);
                        q.push(nxt);
                    }
                }
            }

            for(int i=1;i<=n;i++){
                if(i == START)continue;
                if(mx[i] - dis[i] >= k)ans++;
            }

        }
        cout<<ans<<"\n";
    }
    else{
        vector<int>arr(n+1);

        for(int i=1;i<n;i++){
            int x, y, w;
            cin>>x>>y>>w;
            assert(x == y-1);

            arr[x] = w;
        }
        
    }

    return 0;
}
