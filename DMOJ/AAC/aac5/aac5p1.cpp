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
    int odd = 0;
    int even = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x&1)odd++;
        else even++;
    }
    cout<<((even/2) + (odd/2))<<"\n";

    return 0;
}
