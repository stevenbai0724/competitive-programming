//https://dmoj.ca/problem/acc2p3
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

struct edge{
    int x, mx1, mx2;
};
int mxn = 1e5+5;
int ln = 21;
vector<vector<pair<int, int>>>adj(mxn);
vector<vector<edge>>dp(ln+1, vector<edge>(mxn));
vector<int>dis(mxn);

void dfs(int u, int p){
    for(int i=1;i<ln;i++){
        
        int a = dp[i-1][u].mx1;
        int b = dp[i-1][u].mx2;
        int nxt = dp[i-1][u].x;
        int c = dp[i-1][nxt].mx1;
        int d = dp[i-1][nxt].mx2;

        vector<int>temp{a, b, c, d};

        sort(temp.begin(), temp.end());

        dp[i][u] = {dp[i-1][nxt].x, temp[3], temp[2]};
    }
    for(auto pii: adj[u]){
        int nxt = pii.second;
        int w = pii.first;
        if(nxt == p)continue;

        dp[0][nxt] = {u, w, 0};
        dis[nxt] = dis[u] + 1;

        dfs(nxt, u);

    }
}
int lca(int x, int y){
    if(dis[x] < dis[y]){
        swap(x, y);
    }
    int diff = dis[x] - dis[y];

    for(int i=ln-1;i>=0;i--){
        if(diff&(1<<i)){
            x = dp[i][x].x;
        }
    }

    if(x == y)return x;

    for(int i=ln-1;i>=0;i--){
        if(dp[i][x].x != dp[i][y].x){
            x = dp[i][x].x;
            y = dp[i][y].x;
        }
    }
    return dp[0][x].x;
}
int getDis(int x, int y){
    return dis[x] + dis[y] - 2*dis[lca(x, y)];
}
pair<int, int> solve(int x, int anc){
    int diff = dis[x] - dis[anc];
    int a = 0;
    int b = 0;
    for(int i=ln-1;i>=0;i--){
        if((1<<i)&diff){
            int c = dp[i][x].mx1;
            int d = dp[i][x].mx2;
            x = dp[i][x].x;

            if(c > a){
                b = a;
                a = c;
            }
            else if(c > b){
                b = c;
            }

            if(d > a){
                b = a;
                a = d;
            }
            else if(d > b){
                b = d;
            }
        }
    }

    return {a,b};
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[y].push_back({w,x});
        adj[x].push_back({w,y});
    }

    dfs(1, 0);

    int q; cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        int anc = lca(x, y);

        if(getDis(x, y) < 2)cout<<-1<<"\n";
        else{
            vector<int>temp;

            pair<int, int>pi1 = solve(x, anc);
            pair<int, int>pi2 = solve(y, anc);

            temp.push_back(pi1.first);
            temp.push_back(pi1.second);
            temp.push_back(pi2.first);
            temp.push_back(pi2.second);
            sort(temp.begin(), temp.end());
            cout<<temp[2]<<"\n";
        }
    }

    return 0;
}
