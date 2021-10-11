//https://dmoj.ca/problem/dmopc17c4p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int n; 
int mx = 0;
int START = 0;
vector<vector<pair<int, int>>>adj;
vector<int>colour;
vector<int>parent;
vector<vector<int>>dis(2);

void clear(){
    fill(parent.begin(), parent.end(), 0);
    fill(colour.begin(), colour.end(), 0);
    for(int i=0;i<=1;i++){
        fill(dis[i].begin(), dis[i].end(), 0);
    }
    mx = 0;

}
void dfs(int v, int j){
    colour[v] = 1;

    for(auto p: adj[v]){
        int w = p.first;
        int u = p.second;

        if(colour[u] == 0){
            dis[j][u] = dis[j][v] + w;
            parent[u] = v;
            if(dis[j][u]>mx){
                mx = dis[j][u];
                START = u;
            }

            dfs(u, j);
        }
    }

    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;

    adj.resize(n+1);
    colour.resize(n+1);
    dis[0].resize(n+1);
    dis[1].resize(n+1);
    parent.resize(n+1);

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;

        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    dfs(1, 0);

    clear();
    int a = START;
    dfs(a, 0);
    
    int b = START;

    dfs(b, 1);

    int ans = 0;

    for(int i=1;i<=n;i++){
        if(i==a || i==b )continue;
        ans = max(ans, dis[0][i]);
        ans = max(ans, dis[1][i]);
    }
    cout<<ans<<"\n";




    return 0;
}