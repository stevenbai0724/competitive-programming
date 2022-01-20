//https://dmoj.ca/problem/coci20c4p1
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

    int n; cin>>n;
    set<int>s;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        s.insert(x);
    }
    int ans = 0;
    int m; cin>>m;
    while(m--){
        bool good = true;
        int k; cin>>k;
        for(int i=1;i<=k;i++){
            int x; cin>>x;
            if(s.find(x) != s.end())good = false;
        }
        if(good)ans++;
    }
    cout<<ans<<"\n";

    return 0;
}
