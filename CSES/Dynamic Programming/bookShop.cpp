//https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x;
    cin>>n>>x;
    vector<int>price(n+1);
    vector<int>page(n+1);

    vector<vector<int>>dp(2, vector<int>(x+1));

    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    for(int i=1;i<=n;i++){
        cin>>page[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[1][j] = max(dp[0][j], dp[1][j-1]);
            if(j>=price[i]){
                dp[1][j] = max(dp[1][j], page[i]+dp[0][j-price[i]]);
            }
        }
        for(int j=1;j<=x;j++){
            dp[0][j] = dp[1][j];
        }
    }
    cout<<dp[0][x];


    return 0;
}