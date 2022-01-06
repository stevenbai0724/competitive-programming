//https://dmoj.ca/problem/coci20c6p2
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
    map<string, int>mp;

    vector<vector<pair<int, int>>>adj(n+1);
    
    int cur = 1;
    for(int i=1;i<=m;i++){
        string x, y;
        cin>>x>>y;
        if(mp[x] == 0){
            mp[x] = cur;
            cur++;
        }
        if(mp[y] == 0){
            mp[y] = cur;
            cur++;
        }
        int a = mp[x];
        int b = mp[y];
        int w; cin>>w;
        adj[a].push_back({w,b});


    }

    int qu; cin>>qu;
    while(qu--){
        string s, t;
        cin>>s>>t;
        int START = mp[s];
        int END = mp[t];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

        q.push({0,START});
        vector<int>dis(n+1, 1e18);
        vector<bool>vis(n+1);
        dis[START] = 0;

        while(!q.empty()){
            int y = q.top().second;
            q.pop();
            if(vis[y])continue;
            vis[y] = true;
            

            for(auto p: adj[y]){
                int neww = p.first;
                int newy = p.second;
                if(dis[y] + neww < dis[newy]){
                    dis[newy] = dis[y] + neww;
                    q.push({dis[newy], newy});
                }
            }
        }

        if(dis[END] == 1e18)cout<<"Roger\n";
        else cout<<dis[END]<<"\n";


    }


    return 0;
}
