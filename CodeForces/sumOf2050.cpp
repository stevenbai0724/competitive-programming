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

    int t; cin>>t;

    while(t--){
        int x; cin>>x;

        if(x%2050!=0)cout<<-1<<"\n";
        else{
            int ans = 0;
            string s = to_string(x/2050);

            for(auto c: s){
                ans += c-48;
            }
            cout<<ans<<"\n";
        }
    }
    
    
    return 0;
}