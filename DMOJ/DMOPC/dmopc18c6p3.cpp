//https://dmoj.ca/problem/dmopc18c6p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
int n, m;
int comp = 0;
vector<int>colour;
vector<vector<int>>adj;
void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            dfs(u);
        }
    }
    colour[v] = 1;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;

    colour.resize(n+1);
    adj.resize(n+1);


    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(colour[i]==0){
            comp++;
            dfs(i);
        }
    }

    int need = n-comp;

    if(m-need<=1)cout<<"YES\n";
    else cout<<"NO\n";


    return 0;
}