//https://codeforces.com/problemset/problem/1692/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        int ans = 0 ;
        ans += b > a;
        ans += c > a;
        ans += d > a;
        cout<<ans<<"\n";
    }


    return 0;
}