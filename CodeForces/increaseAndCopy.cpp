//https://codeforces.com/problemset/problem/1426/C
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        double n; cin>>n;
        if(n==1){
            cout<<0<<"\n";
            continue;
        }
        int ans = 1e18;
        int root = sqrt(n);
        for(int i = root - 2; i<=root + 2; i++){
            if(i<1)continue;
            ans = min(ans, (i-1) + (int)ceil((n-i)/i));
        }
        cout<<ans<<"\n";
    }


    return 0;