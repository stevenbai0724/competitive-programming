//https://codeforces.com/problemset/problem/1593/D1
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);
        int mn = 1e18;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mn = min(mn, arr[i]);
        }
        int gcd = 0;

        for(int i=1;i<=n;i++){
            gcd = __gcd(gcd, arr[i] - mn);
        }
        cout<<(gcd > 0 ? gcd : -1)<<"\n";

    }

    return 0;
}