//https://dmoj.ca/problem/tle17c4p3
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

    int n, m, d;
    cin>>n>>m>>d;
    vector<vector<int>>adj(n+1), adj2(n+1);
    vector<int>indegree(n+1);

    for(int i=1;i<=m;i++){
        int x, j;
        cin>>x>>j;
        while(j--){
            int y; cin>>y;
            adj[y].push_back(x);
            adj2[x].push_back(y);
            indegree[x]++;
        }
    }
    for(int i=1;i<=n;i++){
        assert(adj[i].size() <= 1);
    }

    vector<bool>vis(n+1);

    for(int i=1;i<=d;i++){
        int item; cin>>item;
 
        if(vis[item])continue;
        queue<int>q;
        vis[item] = true;
        q.push(item);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(adj[cur].size() == 0)break;
            indegree[adj[cur][0]]--;
            if(indegree[adj[cur][0]] == 0){
                if(!vis[adj[cur][0]]){
                    vis[adj[cur][0]] = true;
                    q.push(adj[cur][0]);
                }
            }
        }
        if(vis[1]){
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";


    return 0;
}