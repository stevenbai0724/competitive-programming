//https://codeforces.com/problemset/problem/1574/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n);

    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    int m; cin>>m;
    while(m--){
        int ans = 1e18;
        int x, y;
        cin>>x>>y;

        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(ind<n) ans = min(ans, max((int)0, y - (sum-arr[ind])));
        if(ind>0) ans = min(ans, max((int)0, x-arr[ind-1]) + max((int)0, y - (sum-arr[ind-1]))) ;

        cout<<ans<<"\n";

    }



    return 0;
}