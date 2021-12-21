//http://www.usaco.org/index.php?page=viewproblem&cpid=1147
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>adj(n+1);
        for(int i=1;i<=m;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool>vis(n+1);
        vector<set<int>>comp;
        vector<int>colour(n+1);
        int now = -1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                now++;
                set<int>s;
                queue<int>q;
                q.push(i);
                vis[i] = true;
                colour[i] = now;
                s.insert(i);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(int nxt: adj[cur]){
                        if(!vis[nxt]){
                            vis[nxt] = true;
                            s.insert(nxt);
                            colour[nxt] = now;
                            q.push(nxt);
                        }
                    }
                }

                comp.push_back(s);



            }
        }   
        int ans = 1e18;
        
        if(comp.size() == 1)assert(colour[1] == colour[n]);
        if(colour[1] == colour[n])cout<<0<<"\n";
        else if(comp.size() ==2){
            cout<<1<<"\n";
        }
        else{
            for(int nxt: comp[colour[1]]){
                auto it = comp[colour[n]].lower_bound(nxt);
                assert(it != comp[colour[n]].end());

                if(it == comp[colour[n]].begin()){
                    int L = *comp[colour[n]].begin();
                    ans = min(ans, (L - nxt)*(L - nxt));
                }
                else{
                    int R = *it;
                    it--;
                    int L = *it;
                    ans = min(ans, min((R-nxt)*(R-nxt), (L-nxt)*(L-nxt)));
                }

            }
            for(int nxt: comp[colour[n]]){
                auto it = comp[colour[1]].lower_bound(nxt);
                assert(it != comp[colour[1]].begin());

                if(it == comp[colour[1]].end()){
                    int L = *comp[colour[1]].rbegin();
                    ans = min(ans, (L - nxt)*(L - nxt));
                }
                else{
                    int R = *it;
                    it--;
                    int L = *it;
                    ans = min(ans, min((R-nxt)*(R-nxt), (L-nxt)*(L-nxt)));
                }

            }
            for(auto st: comp){
                int A = 1e18;
                int B = 1e18;
                if(*st.begin() == 1 || *st.rbegin() == n)continue;
                for(int nxt: st){
                    auto it = comp[colour[1]].lower_bound(nxt);
                    auto it2 = comp[colour[n]].lower_bound(nxt);
                    assert(it != comp[colour[1]].begin() && it2 != comp[colour[n]].end());

                    if(it == comp[colour[1]].end()){
                        int R = *comp[colour[1]].rbegin();
                        A = min(A, (R - nxt)*(R - nxt));
                    }
                    else{
                        int R = *it;
                        it--;
                        int L = *it;
                        A = min(A, min((R-nxt)*(R-nxt), (L-nxt)*(L-nxt)));
                    }
                    

                    if(it2 == comp[colour[n]].begin()){
                        int L = *comp[colour[n]].begin();
                        B = min(B, (L - nxt)*(L - nxt));
                    }
                    else{
                        int R = *it2;
                        it2--;
                        int L = *it2;
                        B = min(B, min((R-nxt)*(R-nxt), (L-nxt)*(L-nxt)));
                    }
                }
                ans = min(ans, A+B);
            }
            
            cout<<ans<<"\n";
            assert(ans != 1e18);
        }
        

    }

    return 0;
}