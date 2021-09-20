//https://codeforces.com/problemset/problem/1538/F
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int L, R;
        cin>>L>>R;
        int ans = 0;

        while(!(L==0 && R==0)){
            ans += R-L;
            L/=10;
            R/=10;
        }
        cout<<ans<<"\n";
    }


    return 0;
}