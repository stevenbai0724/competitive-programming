//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int need = 0;
        need += c;
        need += (b%2)*2;
        if(c>0 && b&1){
            need -= 2;
        }
        a -= need;
        
        if(a>=0 && a%2==0)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}