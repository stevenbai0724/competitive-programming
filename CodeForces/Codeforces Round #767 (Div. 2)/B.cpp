//
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

    int t; cin>>t;
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;

        if(a == b){
            if(a == 1)cout<<"NO\n";
            else cout<<"YES\n";
            continue;
        }
        if(a%2 == 0)a++;
        if(b%2 == 0)b--;
        int cnt = (b-a+2)/2;
        if(cnt <= k)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
