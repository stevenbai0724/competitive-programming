//https://atcoder.jp/contests/abc125/tasks/abc125_c
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

    int n; cin>>n;
    vector<int>arr(n+2), pfx(n+2), sfx(n+2);
    int mod = 1e9 + 7;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    pfx[1] = arr[1];
    for(int i=2;i<=n;i++){
        pfx[i] = __gcd(pfx[i-1], arr[i]);
    }
    sfx[n] = arr[n];
    for(int i=n-1;i>=1;i--){
        sfx[i] = __gcd(sfx[i+1], arr[i]);
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx, __gcd(pfx[i-1], sfx[i+1]));
    }    
    cout<<mx<<"\n";


    return 0;
}