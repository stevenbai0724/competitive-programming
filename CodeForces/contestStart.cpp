//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int n, x, t;
        cin>>n>>x>>t;

        int cover = t/x;
        
        int ans = (max((int)0, n- t/x) * (min(n, t/x)) ) + (((min(n, t/x)))*((min(n, t/x))-1)/2);

        cout<<ans<<"\n"; 


    }


    return 0;
}