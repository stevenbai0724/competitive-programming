//https://cses.fi/problemset/task/1639
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    
    fill(dp.begin(), dp.end(), vector<int>(m+1, 1e9));
    for(int i=1;i<=m;i++){
        dp[1][i] = i;
    }
    for(int i=1;i<=m;i++){
        if(t[i-1]==s[0])dp[1][i] = i-1;
        else dp[1][i] = min(dp[1][i], dp[1][i-1]+1);
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            if(s[i-1]==t[j-1])dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        }
    }
    cout<<dp[n][m];


    return 0;
}