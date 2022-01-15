//https://dmoj.ca/problem/dwite11c2p4
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
vector<vector<int>>adj(1e3 + 5);
vector<bool>vis(1e3 + 5);
class Compare{
    public: 
        bool operator() (int a, int b){
            return adj[a].size() > adj[b].size();
        }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    
    while(t--){
        int n; cin>>n;
        int ans = 0;
        for(int i=1;i<=1000;i++){
            adj[i].clear();
            vis[i] = false;
        }

        for(int i=1;i<n;i++){
            int x, y;
            cin>>x>>y;
            x++;
            y++;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        

        priority_queue<int, vector<int>, Compare>q;

        q.push(1);
        while(!q.empty()){
            int cur = q.top();
            q.pop();
            vis[cur] = true;
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    q.push(nxt);
                }
            }
            ans = max(ans, (int)q.size());
        }
        cout<<ans<<"\n";

    }

    return 0;
}
