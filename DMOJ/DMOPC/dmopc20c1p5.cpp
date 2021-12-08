#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k,m;
    cin >> n >> k >> m;
    vector<int>guards(n+1);
    vector<vector<int>>adj(n+1);
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        guards[i] = x;
    }
    for(int i = 0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(m--){
        int cm;
        cin >> cm;
        if(cm==1){
            int c,a;
            cin >> c >> a;
            guards[c] = a;
        }
        else{
            int u;
            cin >> u;
            vector<bool>vis(n+1);
            vector<bool>vis2(n+1);
            vis[1] = true;
            vis2[u] = true;
            queue<int>q; q.push(1);
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(int nxt: adj[cur]){
                    if(!vis[nxt]){
                        vis[nxt] = true;
                        if(vis2[cur])vis2[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            set<int>s;
            for(int i = 1; i<=n; i++){
                if(vis2[i])s.insert(guards[i]);
            }
            cout << s.size() << "\n";
        }
    }
    return 0;
}