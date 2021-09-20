#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    vector<int>dp(n+1);
    int c = 1e9 + 7;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for(int i =7;i<=n;i++){
        int s = 0;
        for(int j=i-6;j<i;j++){
            s+=dp[j]%c;
        }
        dp[i] = s%c;
 
    }
    cout<<dp[n]%c;
    return 0;
}