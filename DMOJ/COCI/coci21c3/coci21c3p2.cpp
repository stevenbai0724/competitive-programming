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

    vector<vector<int>>adj(n+1);
    int sum = 0;
    vector<bool>processed(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>vis(n+1), vis2(n+1);
    vector<int>dis(n+1), dis2(n+1);
    for(int i=1;i<=n;i++){
        if(!processed[i]){
            processed[i] = true;

            queue<int>q;
            int START = i;
            vis[START] = true;
            int mx = 0;
            q.push(START);

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int nxt: adj[cur]){
                    processed[nxt] = true;
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        dis[nxt] = dis[cur] + 1;
                        if(dis[nxt] > mx){
                            mx = dis[nxt];
                            START = nxt;
                        }
                        q.push(nxt);
                    }
                }

            }

            mx = 0;
            vis2[START] = true;

            q.push(START);

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int nxt: adj[cur]){
                    if(!vis2[nxt]){
                        vis2[nxt] = true;
                        dis2[nxt] = dis2[cur] + 1;
                        if(dis2[nxt] > mx){
                            mx = dis2[nxt];
                            START = nxt;
                        }
                        q.push(nxt);
                    }
                }

            }
            sum += mx + 1;


            
        }

    }
    cout<<sum<<"\n";


    return 0;
}