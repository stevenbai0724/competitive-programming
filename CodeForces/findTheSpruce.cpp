//https://codeforces.com/problemset/problem/1461/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<bool>>arr(n+2, vector<bool>(m+2));
        vector<vector<int>>dp(n+2, vector<int>(m+2));

        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                arr[i][j] = (s[j-1] == '*');
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(!arr[i][j])continue;
                dp[i][j] = 1;
                dp[i][j] = max(dp[i][j], 1+min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]))); 
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans += dp[i][j];
            }
        }
        cout<<ans<<"\n";


    }


    return 0;
}