//https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string

vector<vector<int>>adj;
vector<int>colour;
vector<bool>cat;
vector<int>row;
vector<bool>out;
int n, m;
void dfs(int v){

    colour[v] = 1;
    
    for(int u: adj[v]){
        if(colour[u]==0){
            if(cat[u]){
                row[u]+=row[v];
                if(row[u]>m)continue;
            }
            dfs(u);
         
            
        }
    }

    colour[v] = 2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    colour.resize(n+1);
    cat.resize(n+1);
    row.resize(n+1);
    out.resize(n+1);
    
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==1){
            cat[i] = true;
            row[i] = 1;
        }
    }
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    vector<int>vis(n+1);
    
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                out[cur] = true;
                q.push(nxt);
            }
        }
    }

    dfs(1);
    int cnt = 0;

    for(int i=2;i<=n;i++){
        if(!out[i] && colour[i]==2){
            cnt++;
        }
    }
    cout<<cnt<<"\n";



    return 0;
}