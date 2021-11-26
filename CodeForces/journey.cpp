//https://codeforces.com/contest/839/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
double ans = 0;
void dfs(int v, double c, vector<vector<int>>&adj, vector<int>&colour, vector<double>&dis){
    colour[v] = 1;
    double lo = 0;
    
    for(int u: adj[v]){
        if(colour[u] == 0)lo += 1.0;
    }
    if(!lo){
        ans += dis[v]*c;
        return;
    }
    for(int u: adj[v]){
        if(!colour[u]){
            dis[u] = dis[v] +1;
            dfs(u, c/lo,adj, colour, dis);
            
        }
    }
    colour[v] = 2;
    return ;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>colour(n+1);
    vector<double>dis(n+1);

    for(int i=1;i<n;i++){
        int x, y ;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 1.0, adj, colour, dis);

    cout<<fixed<<setprecision(20)<<ans<<"\n";

    return 0;
}