//https://codeforces.com/problemset/problem/1498/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        string s; cin>>s;
        int n = s.length();

        vector<vector<int>>dp(n+1, vector<int>(4));
        int ans = 1e18;
        for(int i=1;i<=n;i++){
            char ch = s[i-1];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
            dp[i][ch-48] = i;
            if(dp[i][1] != 0 && dp[i][2] != 0 && dp[i][3] != 0){
                ans = min(ans, max(dp[i][1], max(dp[i][2], dp[i][3])) - min(dp[i][1], min(dp[i][2], dp[i][3])) +1 );
            }
        }
        if(ans==1e18)cout<<0<<"\n";
        else cout<<ans<<"\n";

        
    }

    return 0;
}