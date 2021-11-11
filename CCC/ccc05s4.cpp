//https://dmoj.ca/problem/ccc05s4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string>arr(n+2);
        vector<vector<int>>adj(101);

        for(int i=2;i<=n+1;i++){
            cin>>arr[i];
        }
        arr[1] = arr[n+1];
        map<string, int>mp;
        mp[arr[1]] = 1;
        int num = 2;
        for(int i=1;i<=n;i++){

            string cur = arr[i];
            string nxt = arr[i+1];
            if(mp[nxt]==0){
                mp[nxt] = num++;
            }

            adj[mp[cur]].push_back(mp[nxt]);

        }
        queue<int>q;
        vector<bool>vis(101);
        vector<int>dis(101);
        int mx = 0;
        q.push(1);
        vis[1] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    dis[nxt] = 1 + dis[cur];
                    mx = max(mx, dis[nxt]);
                    q.push(nxt);
                }
            }
        }
        cout<<(n-(2*mx))*10<<"\n";

    }


    return 0;
}