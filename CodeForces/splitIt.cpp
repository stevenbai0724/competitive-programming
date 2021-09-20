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
        int n, k;
        cin>>n>>k;
        string s; cin>>s;

        if(2*k ==n){
            cout<<"NO\n";
            continue;   
        }

        bool found = true;

        for(int i=0;i<k;i++){
            if(s[i]!=s[n-i-1])found = false;
        }

        if(found)cout<<"YES\n";
        else cout<<"NO\n";



    }
    
    
    return 0;
}