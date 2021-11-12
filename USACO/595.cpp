//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
//USACO 2016 January Contest Silver P2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin>>n;
    map<int, int>mx, mn;
    for(int i=0;i<=6;i++){
        mn[i] = 1e18;
        mx[i] = 0;

    }
    mn[0] = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum += x;
        sum%=7;
        mn[sum] = min(mn[sum], i);
        mx[sum] = max(mx[sum], i);
    }
    int ans = 0;
    for(int i=0;i<=6;i++){
        ans = max(ans, mx[i]-mn[i]);
    }
    cout<<ans<<"\n";


    return 0;
}