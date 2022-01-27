//http://www.usaco.org/index.php?page=viewproblem2&cpid=576
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
int mxn = 1e5 +1;
int ln = 21;
int mx = 0;
vector<vector<int>>adj(mxn);
vector<vector<int>>dp(ln+1, vector<int>(mxn));
vector<int>dis(mxn), ans(mxn);

void dfs(int u, int p){
    for(int i=1;i<=ln;i++){
        dp[i][u] = dp[i-1][dp[i-1][u]];
    }
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        dp[0][nxt] = u;
        dis[nxt] = dis[u] + 1;
        dfs(nxt, u);
    }
}
int lca(int x, int y){
    if(dis[x] < dis[y]){
        swap(x, y);
    }
    int diff = dis[x] - dis[y];
    for(int i=ln;i>=0;i--){
        if((1<<i)&diff){
            x = dp[i][x];
        }
    }
    if(x == y)return x;

    for(int i=ln;i>=0;i--){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }

    return dp[0][x];
}
void solve(int u, int p){
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        solve(nxt, u);
        ans[u] += ans[nxt];
    }
    mx = max(mx, ans[u]);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    
    int n, q;
    cin>>n>>q;

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    while(q--){
        int x, y;
        cin>>x>>y;
        int anc = lca(x, y);
        ans[x]++;
        ans[y]++;
        ans[anc]--;
        ans[dp[0][anc]]--;
    }

    solve(1, 0);
    cout<<mx<<"\n";


    return 0;
}
