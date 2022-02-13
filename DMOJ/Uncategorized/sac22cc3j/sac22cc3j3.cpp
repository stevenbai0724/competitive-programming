//
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
    map<char, double>mp;
    mp['A'] = 1.0;
    mp['B'] = 0.8;
    mp['C'] = 0.6;
    mp['D'] = 0.4;
    mp['E'] = 0.2;

    double ans = 1.0;

    for(int i=1;i<=n;i++){
        char c; cin>>c;
        ans *= mp[c];
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";

    return 0;
}
