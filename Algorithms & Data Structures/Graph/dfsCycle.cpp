//https://cses.fi/problemset/task/1669/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int n, m;
vector<vector<int>>adj;
vector<int>parent;
vector<int>colour;
bool found = false;
int END;

void dfs(int v){
    colour[v] = 1;
    for(int u : adj[v]){
        if(parent[v]==u)continue;
        if(colour[u] == 0){
            parent[u] = v;
            dfs(u);
            if(found)return;
        }
        if(colour[u] == 1){
            found = true;
            parent[u] = v;
            END = v;
            return;
        }
    }
    colour[v] = 2;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);
    parent.resize(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(colour[i]==0)dfs(i);
        if(found)break;
    }

    if(!found){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int>ans;

    ans.push_back(END);

    int nxt = END;

    while(true){
        nxt = parent[nxt];
        ans.push_back(nxt);
        if(nxt==END)break;
    }
    cout<<ans.size()<<"\n";
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}