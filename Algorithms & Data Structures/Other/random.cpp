//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int unsigned long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    for(int i=1;i<=20;i++){
        int n = rng();
        
        cout<<n<<"\n";
    }

    return 0;
}
