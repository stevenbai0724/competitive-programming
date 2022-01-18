//https://dmoj.ca/contest/mccc3j2
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

    int n, k;
    cin>>n>>k;
    string s; cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'U')k = max((int)0,k-1);
        if(s[i] == 'D')k++;
        if(k==0)ans++;
    }
    cout<<ans<<"\n";

    return 0;
}
