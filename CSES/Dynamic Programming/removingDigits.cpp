//https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> digits(int x){
    vector<int>arr;
    while(x>0){
        arr.push_back(x%10);
        x/=10;
    }
    return arr;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>dp(n+1, 1e18);

    dp[n] = 0;

    for(int i=n;i>=0;i--){
        for(auto x: digits(i)){
            dp[i-x] = min(dp[i-x], dp[i]+1);
        }
    }
    cout<<dp[0];
    return 0;
}