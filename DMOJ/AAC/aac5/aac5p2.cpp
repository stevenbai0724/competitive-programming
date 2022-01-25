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

    vector<int>arr(n+1);
    int GCD = 0;
    for(int i=2;i<=n;i++){
        cout<<"? 1 "<<i<<"\n";
        cout<<flush;
        int x; cin>>x;
        arr[i] = x;
        GCD = __gcd(x, GCD);
    }

    cout<<flush<<"! "<<GCD;;
    for(int i=2;i<=n;i++){
        cout<<" "<<arr[i]/GCD;
    }
    cout<<"\n";

    return 0;
}
