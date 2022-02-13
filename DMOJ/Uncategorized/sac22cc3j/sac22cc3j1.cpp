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

    string s; cin>>s;
    int n = s.length();
    string t = "demello";

    bool found = false;

    for(int i=0;i<=n-7;i++){
        if(s.substr(i, 7) == t)found = true;
        
    }
    if(found)cout<<"liar\n";
    else cout<<"what are we going to do?\n";

    return 0;
}
