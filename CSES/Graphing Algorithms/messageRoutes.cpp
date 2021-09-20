//https://cses.fi/problemset/submit/1667/
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1);
    vector<int>dis(n+1,0);
    vector<int>p(n+1);
    vector<int>ans;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    vis[1] = true;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto x: adj[cur]){
            if(!vis[x]){
                vis[x] = true;
                p[x] = cur;
                q.push(x);
                dis[x] = dis[cur]+1;
            }
        }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<dis[n]+1<<"\n";
    int cur = n;
    ans.push_back(cur);
    while(cur!=1){
        cur = p[cur];
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }


    return 0;
}