//Troyangles
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int ans = 0;
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    vector<vector<char>>arr(n+1, vector<char>(n+1));
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            arr[i][j] = s[j-1];
            ans+= s[j-1]=='#';
        }
    }
    
    for(int i=n-1;i>=1;i--){
        for(int j=2;j<n;j++){
            if(arr[i][j]=='#' && arr[i+1][j]=='#' && arr[i+1][j+1] =='#' && arr[i+1][j-1]=='#'){
                dp[i][j] = min(dp[i+1][j-1], dp[i+1][j+1]) +1;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=dp[i][j];
        }
    }
    cout<<ans;
    return 0;
}