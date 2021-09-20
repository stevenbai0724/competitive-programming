//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    double n, m, a, b;
    cin>>n>>m>>a>>b;
    int ans = 0;
    if(b/m >= a){
        cout<<setprecision(20)<<n*a<<"\n";
        return 0;
    }

    ans += floor(n/m) * b;

    int remainder = n - floor(n/m)*m;

    ans += min(remainder*a, ceil(remainder/m)*b);
    cout<<setprecision(20)<<ans<<"\n";

    return 0;
}