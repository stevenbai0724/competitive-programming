//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int x, y, k;
        cin>>x>>y>>k;

        vector<vector<int>>dp(x+1, vector<int>(y+1));

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(i==1 && j==1)continue;
                if(i==1){
                    dp[i][j] = dp[i][j-1]+1;
                    continue;
                }
                if(j==1){
                    dp[i][j] = dp[i-1][j]+1;
                }
                dp[i][j] = dp[i-1][j] + j;
            }
        }
        if(dp[x][y]==k)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}