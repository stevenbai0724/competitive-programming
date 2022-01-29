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
    int mn = 1e18;
    int ind = 1;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i] < mn){
            mn = arr[i];
            ind = i;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i == ind)continue;
        ans += mn + arr[i];

    }
    cout<<ans<<"\n";


    return 0;
}
