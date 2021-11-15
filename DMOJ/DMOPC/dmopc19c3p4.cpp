//https://dmoj.ca/problem/dmopc19c3p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
int mod = 1e9 + 7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;

    vector<vector<int>>adj(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx, (int)adj[i].size());
    }
    if(mx <= 2){
        int B = 0, R = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='B')B++;
            else R++;
        }
        cout<<((R*(R+1)/2)+(B*(B+1)/2))%mod<<"\n";
        return 0;
    }

    int ans = 0;
    for(int i=1;i<(1<<n);i++){
        vector<bool>use(n+1);
        int START;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                use[j+1] = true;
                START = j+1;
            }
        }
        vector<int>vis(n+1), degree(n+1);
        set<char>st;
        vis[START] = true;
        queue<int>q;
        q.push(START);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(use[nxt] && !vis[nxt]){
                    vis[nxt] = true;
                    degree[cur]++;
                    degree[nxt]++;
                    q.push(nxt);
                }
            }
        }
        if(count(vis.begin(), vis.end(), true) != count(use.begin(), use.end(), true))continue;
        for(int i=1;i<=n;i++){
            if(use[i]){
                if(degree[i] == 1 || degree[i] == 0)st.insert(s[i-1]);
            }
        }
        ans += (st.size()==1);

    }
    cout<<ans<<"\n";

    

    return 0;
}