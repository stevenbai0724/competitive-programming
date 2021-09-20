//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
map<string, int>mp;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;  
    while(t--){
        string s; cin>>s;
        if(mp[s]==0){
            cout<<"OK\n";
            mp[s] = 1;
        }
        else{
            cout<<s+to_string(mp[s])<<"\n";
            mp[s]++;
        }
    }


    return 0;
}