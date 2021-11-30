//https://dmoj.ca/problem/ccc19s4
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

    int n, k;
    cin>>n>>k;

    vector<int>arr(n+1);
    int mx = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mx = max(mx, arr[i]);
    }

    if(k == n){
        cout<<mx<<"\n";
        return 0;
    }

    mx = 0;

    vector<int>pfx(n+2), sfx(n+2);

    for(int i=1;i<=n;i++){
        pfx[i] = max(pfx[i-1], arr[i]);
        sfx[n-i+1] = max(sfx[n-i+2], arr[n-i+1]);
    }
    for(int i=n-k;i<=k;i++){
        mx = max(mx, pfx[i] + sfx[i+1]);
    }
    cout<<mx<<"\n";

    return 0;
}