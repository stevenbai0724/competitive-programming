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

    int n; cin>>n;

    vector<int>indegree(n+1);
    vector<vector<int>>adj(n+1);
    vector<int>dis(n+1);
    vector<bool>vis(n+1);
    vector<int>val(n+1);
    queue<int>q;

    for(int i=1;i<=n;i++){
        int w, r;
        cin>>w>>r;
        val[i] = w;
        if(r == 0){
            q.push(i);
        }
        indegree[i] = r;
        for(int j=1;j<=r;j++){
            int x; cin>>x;
            if(x == i)continue;

            adj[x].push_back(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        dis[cur] += val[cur];
        q.pop();
        for(int nxt: adj[cur]){
            indegree[nxt] --;
            dis[nxt] = max(dis[nxt], dis[cur]);
            if(!indegree[nxt])q.push(nxt);
        }

    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dis[i]);
    }

    cout<<ans<<"\n";



 



    return 0;
}
