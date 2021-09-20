//https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
int n, m;
vector<vector<int>>adj;
vector<int>ans;
bool found = false;

void dfs(int v, int team){
    ans[v] = team;
    for(int u: adj[v]){
        if(ans[u]==ans[v])found = true;
        if(ans[u]==0){
            if(ans[v]==1)dfs(u, 2);
            else dfs(u,1);
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;

    adj.resize(n+1);
    ans.resize(n+1);

    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]){
            dfs(i, 1);
        }
    }
    if(found)cout<<"IMPOSSIBLE\n";
    else{
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
    }


    return 0;
}