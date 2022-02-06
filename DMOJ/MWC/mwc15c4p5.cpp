//https://dmoj.ca/problem/mwc15c4p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x, y;
    cin>>n>>x>>y;

    vector<int>vert{0};
    map<int, int>mp, vis;

    set<int>st;
    while(n--){
        char c;
        cin>>c;
        if(c=='h'){
            int s, d;
            cin>>s>>d;
            mp[s] = max(mp[s], d);
            st.insert(s);
        }else{  
            int d; cin>>d;
            
            if(vis[d]!=1){
                vis[d] = 1;
                vert.push_back(d);
            }

        }
    }

    vert.push_back(x);
    sort(vert.begin(), vert.end());
    int ans = (int)vert.size() - 2;
    for(int x: st){
        int d = mp[x];
        auto it = upper_bound(vert.begin(), vert.end(), d) - vert.begin();

        it--;

        ans += it;
    }
    cout<<ans<<"\n";

    return 0;
}
