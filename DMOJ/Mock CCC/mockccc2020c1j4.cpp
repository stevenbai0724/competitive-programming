//https://dmoj.ca/problem/mockccc2020c1j4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    vector<int>pfx(n+2), sfx(n+2);
    pfx[0] = 1e9;
    sfx[n+1] = 1e9;
    for(int i=0;i<n;i++){
        pfx[i+1] = pfx[i] + 1;
        if(s[i] == '1') pfx[i+1] = 1;

    }
    for(int i=n-1;i>=0;i--){
        sfx[i+1] = sfx[i+2] + 1;
        if(s[i]=='1')sfx[i+1] = 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0')ans += (min(sfx[i+1], pfx[i-1]));
    }
    cout<<ans<<"\n";

    return 0;
}