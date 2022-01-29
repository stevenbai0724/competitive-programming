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
int mod = 1e9 + 7;
vector<int>dis(100);
vector<vector<int>>adj(100);
int f(int b, int e){
    int cur = b;
    int ans = 1;
    for(int i=0;i<=30;i++){
        if((1<<i)&e){
            ans *= cur;
            ans %= mod;
        }
        cur *= cur;
        cur %= mod;
    }
    return ans;
}
void dfs(int u, int p){
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        dis[nxt] = dis[u] + 1;
        dfs(nxt, u);
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, r, k;
    cin>>n>>r>>k;
    int m = n-1;

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int a, b;
    cin>>a>>b;
    dfs(a, 0);

    int edges = dis[b];

    int ans = f(k, edges);
    ans -= k;
    if(ans < 0)ans += mod;
    ans %= mod;

    if(m > edges){
        ans *= f(k, m-edges);
        ans %= mod;
    }

    cout<<ans<<"\n";

    
    return 0;
}
