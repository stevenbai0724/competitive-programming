//https://dmoj.ca/problem/sac22cc2p3
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

    int n, r;
    cin>>n>>r;
    vector<vector<pair<int, int>>>adj((1<<(n+1))+1);

    for(int i=1;i<= (1<<n) - 1;i++){
        int x, y, z, w;
        cin>>x>>y>>z>>w;
        adj[x].push_back({y,w});
        adj[x].push_back({z,0});
    }
    vector<int>dis((1<<(n+1))+1);
    queue<int>q;
    dis[1] = r;
    q.push(1);
    int mx = r;
    while(!q.empty()){
        int cur = q.front();
        mx = max(mx, dis[cur]);
        q.pop();
        for(auto p: adj[cur]){
            int nxt = p.first;
            int weight = p.second;
            dis[nxt] = weight + dis[cur];
            q.push(nxt);
        }
    }
    cout<<mx<<"\n";

    return 0;
}