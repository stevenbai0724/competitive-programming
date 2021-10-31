//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 2;
    while(t--){
        int n; cin>>n;


        vector<int>indegree(n+1);
        vector<vector<int>>adj(n+1);
        queue<int>q;
        vector<int>vis(n+1);
        int cnt = 0;

        for(int i=1;i<=n;i++){
            int x; cin>>x;

            if(x==i)continue;

            adj[x].push_back(i);

            indegree[i]++;


        }


    }


    return 0;
}