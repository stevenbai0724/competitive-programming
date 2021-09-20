//https://cses.fi/problemset/task/1744s
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=j)dp[i][j] = 1e18;
            else {
                dp[i][j] = 0;
                continue;
            } 
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j], 1+dp[k][j] + dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";

    
    return 0;
}