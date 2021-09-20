//https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int>colour;
vector<vector<int>>adj;
vector<int>p;
int cur = 0;
int s = 0;
bool found = false;
void dfs(int v){
    colour[v] = 1;
    for(int u:adj[v]){
        if(p[v]==u)continue;
        if(colour[u]==0){
            p[u] = v;
            dfs(u);
            if(found)return;
        }
        if(colour[u]==1){
            p[u] = v;
            cur = u;
            s = u;
            found = true;
            return;
        }
    }
    colour[v]=2;
    if(found ||count(colour.begin(), colour.end(),2)==n)return;
}
void cycle(){
    for(int i=1;i<=n;i++){
        if(found)return;
        if(colour[i]==0)dfs(i);
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);
    p.resize(n+1);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cycle();
    if(!found){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    vector<int>ans;
    ans.push_back(cur);
    cur = p[cur];
    while(cur!=s){
        ans.push_back(cur);
        cur = p[cur];
    }
    ans.push_back(s);
    cout<<ans.size()<<"\n";
    
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}