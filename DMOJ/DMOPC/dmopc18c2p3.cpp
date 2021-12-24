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

    int n, m, k, a, b;
    cin>>n>>m>>k>>a>>b;

    vector<bool>shop(n+1);

    for(int i=1;i<=k;i++){
        int x; cin>>x;
        shop[x] = true;
    }
    vector<vector<int>>adj(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int>q;
    vector<bool>vis1(n+1), vis2(n+1);
    vector<int>dis1(n+1), dis2(n+1);

    q.push(a);
    vis1[a] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis1[nxt]){
                vis1[nxt] = true;
                dis1[nxt] = dis1[cur] + 1;
                q.push(nxt);
            }
        }
    }
    q.push(b);
    vis2[b] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis2[nxt]){
                vis2[nxt] = true;
                dis2[nxt] = dis2[cur] + 1;
                q.push(nxt);
            }
        }
    }
    int ans = 1e18;
    for(int i=1;i<=n;i++){
        if(shop[i]){
            ans = min(ans, dis1[i] + dis2[i]);
        }
    }
    cout<<ans<<"\n";

    return 0;
}