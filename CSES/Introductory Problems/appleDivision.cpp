//https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int sum = 0;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int ans = 1e18;
    for(int i = 1;i<(1<<n);i++){
        int temp = 0;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                temp+=arr[j];
            }
        }
        ans = min(ans, abs((sum-temp)-temp));

    }
    cout<<ans<<"\n";



    return 0;
}