//https://cses.fi/problemset/task/1095
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
int mod = 1e9+7;
int f(int b, int e){
    int cur = b;
    int ans = 1;
    for(int i=0;i<=30;i++){
        if((1<<i)&e){
            ans *= cur;
            ans %= mod;
        }
        cur *= cur;
        cur %= mod;
    }
    return ans;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin>>q;
    while(q--){
        int b, e;
        cin>>b>>e;
        cout<<f(b,e)<<"\n";
    }
    return 0;
}
