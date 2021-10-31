//https://dmoj.ca/problem/coci15c3p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

vector<vector<int>>adj;
vector<int>dis;
vector<int>colour;

void dfs(int v){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u]==0){
            dis[u] = dis[v] + 1;
            dfs(u);
        }
    }

    colour[v] = 2;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    map<pair<int, int>, bool>mp;

    int n; cin>>n;

    adj.resize(n+1);
    dis.resize(n+1);
    colour.resize(n+1);

    vector<pair<int, int>>edge;

    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edge.push_back({x,y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    for(auto p: edge){
        int x = p.first;
        int y = p.second;

        if(dis[x]&1)cout<<0<<"\n";
        else cout<<1<<"\n";
    }



    return 0;
}