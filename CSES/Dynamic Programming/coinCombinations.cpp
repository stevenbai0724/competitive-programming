//https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, s;
    cin>>n>>s;
    int c = 1e9+7;
    int mn = 1e9;

    vector<int>arr(n+1);

    for(int i =1;i<=n;i++){
        cin>>arr[i];
        mn = min(mn, arr[i]);
    }
    if(mn>s){
        cout<<0;
        return 0;
    }
    vector<int>dp(s+1);
    for(int i =1;i<=n;i++){
        dp[arr[i]] = 1;
    }
    for(int i =1;i<=s;i++){
        for(int j=1;j<=n;j++){
            if(i>=arr[j]){
                dp[i] += (dp[i-arr[j]])%c;
            }
        }
    }
    cout<<dp[s]%c;

    


    return 0;
}