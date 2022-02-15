#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int mn = 0;
    int mx = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        mn = __gcd(mn, x);
        mx = max(x,mx);
    }

    cout<<mn<<"\n"<<mx<<"\n";

    return 0;
}