//https://cses.fi/problemset/task/1682
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<vector<int>>>adj;
vector<bool>vis;

void dfs(int v, int a){
    vis[v] = true;
    for(int u: adj[a][v]){
        if(!vis[u]){
            dfs(u,a);
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(3);
    adj[1].resize(n+1);
    adj[2].resize(n+1);
    vis.resize(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[1][x].push_back(y);
        adj[2][y].push_back(x);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n"<<1<<" "<<i<<"\n";
            return 0;
        }
    }
    fill(vis.begin(), vis.end(), false);
    dfs(1,2);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n"<<i<<" "<<1<<"\n";
            return 0;
        }
    }
    cout<<"YES\n";


    return 0;
}