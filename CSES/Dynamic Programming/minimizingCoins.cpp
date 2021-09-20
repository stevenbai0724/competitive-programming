#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x;
    cin>>n>>x;
    vector<int>arr(n+1);
    int mx = 0;


    for(int i =1;i<=n;i++){
        cin>>arr[i];
        mx = max(mx, arr[i]);
    }
    vector<int>dp(max(mx, x)+1);
    for(int i =1;i<=x;i++){
        if(dp[i]!=1) dp[i] = (int)1e9;
    }

    for(int i =1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i-arr[j]>=0){
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }
    if(dp[x]!=1e9)cout<<dp[x];
    else cout<<-1;
    return 0;   
}