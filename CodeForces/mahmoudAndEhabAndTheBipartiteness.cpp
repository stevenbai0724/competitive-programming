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

    int n; cin>>n;
    vector<bool>colour(n+1);
    vector<bool>vis(n+1);
    int T = 0, F = 1;

    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int>q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                colour[nxt] = !colour[cur];
                q.push(nxt);
                if(colour[nxt])T++;
                else F++;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(colour[i]){
            ans += F - adj[i].size();
        }
        else ans += T - adj[i].size();
    }
    cout<<ans/2<<"\n";


    

    return 0;
}