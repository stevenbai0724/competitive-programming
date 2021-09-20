//https://codeforces.com/problemset/problem/455/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>freq(1e5+2);
    vector<int>arr{0};
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        freq[x]++;
    }
    for(int i=1;i<=1e5+2;i++){

        arr.push_back(freq[i]*i);
    }
    int mx = 0;
    vector<int>dp(1e5+2);
    dp[1] = arr[1];
    for(int i=2;i<=1e5;i++){
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
        mx = max(mx, dp[i]);
    }
    cout<<mx<<"\n";




    return 0;
}