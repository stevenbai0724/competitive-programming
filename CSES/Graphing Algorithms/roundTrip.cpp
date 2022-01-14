//https://cses.fi/problemset/task/1669/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
bool found = false;
int START;
void dfs(int v, vector<int>&colour, vector<int>&parent, vector<vector<int>>&adj){

    colour[v] = 1;

    for(int u: adj[v]){
        if(parent[v] == u)continue;
        if(colour[u] == 0){
            parent[u] = v;
            dfs(u, colour, parent, adj);
            if(found)return;
        }
        if(colour[u] == 1){
            found = true;
            parent[u] = v;
            START = u;
            if(found)return;
        
        }
    }
    colour[v] = 2;


    return; 
}
signed main(){

    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>colour(n+1), parent(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(colour[i] == 0)dfs(i,colour, parent, adj);
        if(found)break;
    }

    if(!found){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int>ans{START};

    int nxt = parent[START];

    while(true){
        ans.push_back(nxt);
        nxt = parent[nxt];
        if(nxt == START)break;
    }

    ans.push_back(START);

    cout<<ans.size()<<"\n";
    for(int x: ans)cout<<x<<" ";
    cout<<"\n";




    return 0;
}