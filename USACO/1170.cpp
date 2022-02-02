//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<vector<int>>adj(1e5+1);
    for(int i=1;i<=1e5;i++){

        if(i%2==0)adj[i].push_back(i/2);
        adj[i].push_back(i+1);
        adj[i].push_back(i*2);
    }

    int t; cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        queue<int>q;
        vector<bool>vis(1e5+1);
        vector<int>dis(1e5+1);
        vector<int>parent(1e5+1);

        vis[x] = true;
        q.push(x);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
              if(nxt > 1e5)continue;
                if(!vis[nxt]){
                    vis[nxt] = true;
                    parent[nxt] = cur;
                    dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                  
                }
            }
        }
        for(int j=x;j<=y;j++){
            vector<int>ans;
            int cur = j;
            while(cur!=x){
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(x);
            reverse(ans.begin(), ans.end());

            for(int z: ans)cout<<z<<" ";
            cout<<"\n";
        }
        
        cout<<"\n";
   
    }

   return 0;
}
