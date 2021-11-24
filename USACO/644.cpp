//http://www.usaco.org/index.php?page=viewproblem2&cpid=644
//USACO 2016 Open Contest Silver P3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>close(n+1);
    vector<int>arr(n+1);
    int START;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    START = arr[n];

    for(int i=1;i<=n;i++){
        queue<int>q;
        vector<bool>vis(n+1);
        q.push(START);
        vis[START] = true;
        int cnt = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt] && !close[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                    cnt++;
                }
            }
        }
        if(cnt == n-i+1)cout<<"YES\n";
        else cout<<"NO\n";
        close[arr[i]] = true;
    }




    return 0;
}