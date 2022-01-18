//https://dmoj.ca/contest/mccc3j3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    string s, t;
    cin>>s>>t;

    vector<int>freq1(26), freq2(26);

    for(int i=0;i<n;i++){
        freq1[s[i]-'A']++;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        freq2[t[i]-'A']++;
    }
    int mn = 1e18;
    int mx = 0;

    for(int i=0;i<26;i++){
        ans += freq1[i] * freq2[i];
    }

    for(int i=0;i<26;i++){
        
        
        if(freq2[i] != 0){
            mn = min(mn, freq1[i]);
        }
        mx = max(mx, freq1[i]);
        
    }

    ans += mx;
    ans -= mn;

    cout<<ans<<"\n";







    return 0;
}
