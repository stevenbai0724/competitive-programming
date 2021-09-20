//https://codeforces.com/problemset/problem/698/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1,0);
    vector<int>dp(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    dp[1] = arr[1];

    for(int i=2;i<=n;i++){
        
        if(arr[i]==0)continue;
        else if(arr[i]==1){
            if(dp[i-1]==1)continue;
            else dp[i] = 1;
        }
        else if(arr[i]==2){
            if(dp[i-1]==2)continue;
            else dp[i] = 2;
        }
        else{
            if(dp[i-1]==0 || dp[i-1] ==3)dp[i] = 3;
            else if(dp[i-1]==1)dp[i] = 2;
            else if(dp[i-1]==2)dp[i] = 1;

        }

    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        ans += dp[i]==0;
    }
    cout<<ans<<"\n";




    return 0;
}