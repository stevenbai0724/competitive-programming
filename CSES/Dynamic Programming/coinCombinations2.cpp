//https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;
    int m = 1e9+7;
 
    vector<int>dp(x+1);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        int c; cin>>c;
        for(int j = c;j<=x;j++){
            dp[j] = (dp[j-c] + dp[j])%m;
        }

    }
    cout<<dp[x];
    
    return 0;
}