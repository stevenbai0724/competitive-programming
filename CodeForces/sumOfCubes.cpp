//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

gp_hash_table<int, int>mp;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    for(int i=1;i<=9999;i++){
        mp[i*i*i] = 1;
    }
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        for(int i=1;i*i*i<=n;i++){
            int b = n- (i*i*i);
            if(mp[b]!=0){
                cout<<"YES\n";
                goto nxt;
            }
        }
        cout<<"NO\n";

        nxt:;

    }

    return 0;
}