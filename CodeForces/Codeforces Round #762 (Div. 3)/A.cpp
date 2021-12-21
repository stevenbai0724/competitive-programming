//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        if(s.substr(0, n/2) != s.substr(n/2) || n&1)cout<<"NO\n";
        else if(s.substr(0, n/2) == s.substr(n/2)) cout<<"YES\n";
    }

    return 0;
}