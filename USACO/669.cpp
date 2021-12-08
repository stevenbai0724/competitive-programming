//http://www.usaco.org/index.php?page=viewproblem2&cpid=669
//USACO 2016 December Contest Gold P1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
void dfs(int v, vector<vector<int>>&adj, vector<int>&colour){
    colour[v] = 1;
    for(int u: adj[v]){
        if(colour[u] == 0){
            dfs(u,adj, colour);
        }
    }
    colour[v] = 2;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin>>n;

    vector<pair<int, int>>arr(n+1);

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        arr[i] = {x,y};
    }

    int L = -1;
    int R = 1e18;

    while(L+1<R){
        int m = (L+R)/2;

        vector<vector<int>>adj(n+1);
        vector<int>colour(n+1);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                int a = abs(arr[i].first - arr[j].first);
                int b = abs(arr[i].second - arr[j].second);
                if(a*a + b*b <=m)adj[i].push_back(j);
            }
        }
        dfs(1, adj, colour);

        if(count(colour.begin(), colour.end(), 2) == n)R = m;
        else L = m;
    }
    cout<<R<<"\n";

  


    return 0;
}