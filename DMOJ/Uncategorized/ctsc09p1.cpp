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
    bool first = true;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }   
    int ans = 0;

    for(int i=n;i>=1;i--){
        if(arr[i] == 2 || arr[i] == 3){
            first = false;
            ans++;
        }
        if(arr[i] == 1){
            if(!first){
                ans += 2;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
