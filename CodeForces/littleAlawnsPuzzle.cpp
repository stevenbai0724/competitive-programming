//https://codeforces.com/problemset/problem/1534/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    int mod = 1e9 + 7;
    while(t--){
        
        int n; cin>>n;
        
        vector<int>arr1(n+1), arr2(n+1), ind1(n+1), ind2(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr1[i];
            ind1[arr1[i]] = i;
        }
        for(int i=1;i<=n;i++){
            cin>>arr2[i];
            ind2[arr2[i]] = i;
        }

        vector<vector<int>>adj(n+1);

        vector<int>vis(n+1);

        for(int i=1;i<=n;i++){
            int one = ind2[arr1[i]];
            int two = ind1[arr2[i]];

            adj[i].push_back(one);
            if(two!=one)adj[i].push_back(two);
        }

        int ans = 1;
        for(int i=1;i<=n;i++){  
            if(vis[i])continue;

            queue<int>q;
            q.push(i);
            vis[i] = true;

            while(!q.empty()){
                int cur = q.front();    
                q.pop();
                for(int nxt: adj[cur]){
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }

            }
            ans *= 2;
            ans %= mod;
        }
        cout<<ans<<"\n";

        

    }


    return 0;
}