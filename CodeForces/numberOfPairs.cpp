//https://codeforces.com/problemset/problem/1538/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int n, l, r;
        cin>>n>>l>>r;

        vector<int>arr(n+1);
        arr[0] = -1e9;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = 0;

        for(int i=1;i<=n;i++){
            ans += upper_bound(arr.begin(), arr.end(), r - arr[i]) - arr.begin();
            ans -= lower_bound(arr.begin(), arr.end(), l - arr[i]) - arr.begin();
            if (l <= 2 * arr[i] && 2 * arr[i] <= r) {
               ans--;
            }
        }
        cout<<ans/2<<"\n";




        
    }

    return 0;
 
}