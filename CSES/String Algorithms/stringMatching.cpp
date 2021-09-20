//https://cses.fi/problemset/task/1753
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s,t;
    cin>>s>>t;
    int base = 131;
    int n = s.length();
    int m = t.length();
    vector<int>hashes(n+1);
    vector<int>power(n+1);
    power[0] = 1;
    int hash2 = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        power[i] = power[i-1]*base;
        power[i]%=mod;
        hashes[i] = hashes[i-1]*base+s[i-1];
        hashes[i]%=mod;
    }
    for(int i=0;i<m;i++){
        hash2*=base;
        hash2+=t[i];
        hash2%=mod;
    }
    for(int i=m;i<=n;i++){
        int hsh = hashes[i]-(hashes[i-m]*power[m])%mod;
        hsh+=mod;
        hsh%=mod;

        if(hsh==hash2)ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
