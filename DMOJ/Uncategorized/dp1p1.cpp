//https://dmoj.ca/problem/dp1p1
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1), dp(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[2];

    for(int i=3;i<=n;i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
    }

    cout<<dp[n]<<"\n";

    return 0;
}