//https://codeforces.com/problemset/problem/1573/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {

    cin.tie(nullptr)->sync_with_stdio(false);


    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<int>odd(n+1), even(n+1), ind(2*(n+1));

        for(int i=1;i<=n;i++){
            cin>>odd[i];
            ind[odd[i]] = i;
        }
        for(int i=1;i<=n;i++){
            cin>>even[i];
            ind[even[i]] = i;
        }

        int mn = 1e18;
        int ans = 1e18;
        for(int i=2;i<=2*n;i+=2){
            mn = min(mn, ind[i-1]-1);
            ans = min(ans, mn + ind[i]-1);
        }
        cout<<ans<<"\n";
    }

    return 0;
}
