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
        int n, c0, c1, h;
        string s;

        cin>>n>>c0>>c1>>h>>s;

        if(h+c0<c1)c1 = h+c0;
        else if(h+c1<c0)c0 = h+c1;

        int ans = 0;

        for(auto c: s){
            if(c=='1')ans+=c1;
            else ans+=c0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}