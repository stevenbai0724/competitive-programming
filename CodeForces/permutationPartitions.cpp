//https://codeforces.com/problemset/problem/1326/C
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
    
    int mod = 998244353;

    int n, k;
    cin>>n>>k;

    vector<int>arr(n+1), use(n+1);
    int L = 1e18;
    int R = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i] >= n-k+1){
            use[arr[i]] = true;
            L = min(L, i);
            R = max(R, i);
        }
    }
    int ans = 1;

    for(int i=L;i<R;i++){
        int j = i;
        assert(use[arr[i]]);
        while(!use[arr[j+1]] && j<R ){
            j++;
        }
        int len = j-i+1;
        ans *= len;
        ans %= mod;
        i = j;
    }
    cout<<(n*(n+1))/2 - ((n-k) * (n-k+1))/2<<" "<<ans<<"\n";

    return 0;
}