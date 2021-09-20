//https://codeforces.com/contest/839/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
int n;
vector<vector<int>>adj;
vector<double>dis;

void dfs(int v, int parent){

    for(auto u: adj[v]){
        if(parent==u)continue;
            dis[u] = dis[v]+1;
            dfs(u, v);
        
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    adj.resize(n+1);
    dis.resize(n+1);

    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    int cnt = 0;
    double sum = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            cnt++;
            sum += dis[i];
  
        }
    }
    cout<<setprecision(20)<<fixed<<sum/cnt<<"\n";
    return 0;
}