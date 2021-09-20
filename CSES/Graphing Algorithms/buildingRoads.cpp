//https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj;
int n,m;
vector<int>colour;
vector<int>ans;

void dfs(int v){
    colour[v] = 1;
    for(int u:adj[v]){
        if(colour[u]==0){
            dfs(u);
        }
    }
    colour[v] = 2;

}
void comp(){
    for(int i=1;i<=n;i++){
        if(colour[i]==0){
            ans.push_back(i);
            dfs(i);
        }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    comp();
    cout<<ans.size()-1<<"\n";

    for(int i=1;i<ans.size();i++){
        cout<<ans[0]<<" "<<ans[i]<<"\n";
    }
    

    return 0;
}