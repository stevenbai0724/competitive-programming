//https://codeforces.com/contest/1452/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        double sum  = 0;
        int mx = 0;
        int ans = 0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            mx = max(mx, arr[i]);
        }  
        int k = max(mx, (int)ceil(sum/(n-1)));
        cout<<setprecision(100)<<k*(n-1) - sum<<"\n";

    }

    return 0;
}