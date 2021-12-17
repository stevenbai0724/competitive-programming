//https://dmoj.ca/problem/coci21c2p2
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

    int n, m, q;
    cin>>n>>m>>q;
    
    vector<vector<int>>adj(n+1);

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            adj[x].push_back(j);
            adj[j].push_back(x);
        }
    }

    vector<int>colour(n+1);
    vector<bool>vis(n+1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            queue<int>q;
            vis[i] = true;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                colour[cur] = cnt;
                for(int nxt: adj[cur]){
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<(colour[x] == colour[y] ? "DA\n" : "NE\n");
    }
    


    return 0;
}