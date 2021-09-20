#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int>arr(3);
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }

    vector<int>dp(4001);

    dp[arr[0]] = 1;
    dp[arr[1]] = 1;
    dp[arr[2]] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(i-arr[j]<=0 || dp[i-arr[j]]==0)continue;
            dp[i] = max(dp[i], dp[i-arr[j]]+1);
        }
    }

    cout<<dp[n]<<"\n";

    return 0;

}