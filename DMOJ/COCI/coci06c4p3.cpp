//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int num; cin>>num;

    for(int i=1;i<n;i++){
        int x; cin>>x;
        int gcd = __gcd(x,num);

        cout<<num/gcd<<"/"<<x/gcd<<"\n";
    }
 
    return 0;
}