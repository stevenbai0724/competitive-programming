//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9+7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int n = s.length();
    int base = 131;
    vector<int>hashes(n+1);
    vector<int>power(n+1); power[0] = 1;
    vector<int>ans;

    for(int i=1;i<=n;i++){
        power[i] = power[i-1]*base;
        power[i]%= mod;
        hashes[i] = hashes[i-1]*base + s[i-1];
        hashes[i]%=mod;
    }
    for(int i=1;i<n;i++){
        int hsh1 = hashes[i];
        int hsh2 = hashes[n] - (hashes[n-i]*power[i])%mod;
        hsh2 += mod;
        hsh2 %= mod;
        if(hsh1==hsh2)ans.push_back(i);
    }
    for(auto x: ans){
        cout<<x<<" ";
    }

    return 0;
}