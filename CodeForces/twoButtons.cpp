//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(1e4+1);

    for(int i=2;i<=10000;i++){
        adj[i].push_back(i-1);
    }
    for(int i=1;i<=5000;i++){
        adj[i].push_back(i*2);
    }
    vector<int>dis(1e4+1);
    vector<int>vis(1e4+1);

    queue<int>q;
    vis[n] = true;
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int to: adj[cur]){
            if(!vis[to]){
                vis[to] = true;
                dis[to] = dis[cur]+1;
                q.push(to);
            }
        }
    }
    cout<<dis[m]<<"\n";


    return 0;
}