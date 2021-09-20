#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<vector<char>>arr(n+1, vector<char>(n+1));
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    int c = 1e9 + 7;
    for(int i =1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            arr[i][j] = s[j-1];
        }
    }  
    
    if(arr[1][1]=='*' ||arr[n][n]=='*'){
        cout<<0;
        return 0;
    }
    
    dp[1][1] =1;

    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int count = 0;
            if(i==1 && j==1)continue;

            if(arr[i][j-1]=='.'){
                count += (dp[i][j-1])%c;
            }
            if(arr[i-1][j]=='.'){
                count += (dp[i-1][j])%c;
            }
            dp[i][j] = count%c;
        }
    }
    cout<<dp[n][n];

    return 0;   
}