//https://dmoj.ca/problem/dmopc16c4p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, f;
    cin>>n>>f;
    vector<set<pair<int, int>>>flavour(n+5);
    vector<int>dis(n+5);
    vector<set<int>>sell(n+5);

    for(int i=1;i<=n;i++){
        cin>>dis[i];
    }

    for(int i=1;i<=f;i++){
        int a, b;
        cin>>a>>b;
        flavour[b].insert({dis[a], a});
        sell[a].insert(b);
        assert(b <= n);
    }

    int q; cin>>q;
    while(q--){
        char c; cin>>c;
        if(c=='A'){
            int x, k;
            cin>>x>>k;
            assert(k<=n);
            sell[x].insert(k);
            flavour[k].insert({dis[x], x});


        }
        if(c=='S'){
            int x, k;
            cin>>x>>k;
            assert(k<=n);
            if(sell[x].find(k) != sell[x].end()){
                sell[x].erase(k);
                flavour[k].erase({dis[x], x});
            }
        }
        if(c=='E'){
            int x, k;
            cin>>x>>k;
    
            for(auto num: sell[x]){
                flavour[num].erase({dis[x],x});
            }
            sell[x].clear();
            dis[x] = k;
        }
        if(c=='Q'){
            int x; cin>>x;

            if(flavour[x].empty())cout<<-1<<"\n";
            else cout<<(*flavour[x].begin()).second<<"\n";
        }
    }


    return 0;
}