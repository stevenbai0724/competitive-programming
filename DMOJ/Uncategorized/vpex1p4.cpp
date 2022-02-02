//https://dmoj.ca/problem/vpex1p4
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
int mxn = 1e5 + 2;
int ln = 21;
vector<vector<pair<int, int>>>adj(mxn);
vector<vector<int>>ans(ln+1, vector<int>(mxn));
vector<int>dis(mxn), lvl(mxn);
void dfs(int u, int p){
    for(int i=1;i<=ln;i++){
        ans[i][u] = ans[i-1][ans[i-1][u]];
    }

    for(auto pi: adj[u]){
        int nxt = pi.second;
        int w = pi.first;
        if(nxt == p)continue;
        ans[0][nxt] = u;
        dis[nxt] = dis[u] + w;
        lvl[nxt] = lvl[u] + 1;
        dfs(nxt, u);
    }
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]){
        swap(x, y);
    }
    int diff = lvl[x] - lvl[y];
    for(int i=ln;i>=0;i--){
        if(diff&(1<<i)){
            x = ans[i][x];
        }
    }
    if(x == y)return x;

    for(int i=ln;i>=0;i--){
        if(ans[i][x] != ans[i][y]){
            x = ans[i][x];
            y = ans[i][y];
        }
    }
    return ans[0][x];
}
int getDis(int x, int y){
    return dis[x] + dis[y] - 2*dis[lca(x, y)];
}
struct edge{
    int a, b, c, d;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, d;
    cin>>n>>d;

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    dfs(1, 0);

    vector<edge>dp(d+1);

    dp[0] = {1,0,1,0};

    for(int i=1;i<=d;i++){
        int x, y;
        cin>>x>>y;


        int a = dp[i-1].a;
        int b = dp[i-1].b;
        int c = dp[i-1].c;
        int d = dp[i-1].d;

        dp[i].a = x;
        dp[i].c = y;

        dp[i].b = min(b + getDis(a, y) + getDis(y, x), d + getDis(c, y) + getDis(y, x));
        dp[i].d = min(b + getDis(a, x) + getDis(x, y), d + getDis(c, x) + getDis(x, y));

    }

    cout<<min(dp[d].b, dp[d].d)<<"\n";

    return 0;
}
