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
    
    int n,m;
    cin>>n>>m;

    if(m==1){
        int ans = (n)*(n-1)/2;
        cout<<ans<<" "<<ans<<"\n";
        return 0;
    }

    int mx = n%m; 
    int mn = m-mx;
    int group = n/m;

    cout<<(group*(group-1)/2*mn)+((group+1)*group/2*mx)<<" ";

    cout<<(n-m+1)*(n-m)/2<<"\n";



  

    return 0;
}