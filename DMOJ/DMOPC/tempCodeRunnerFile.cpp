//
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

    string verb, noun, s;
    cin>>verb, noun;

    char c = noun[noun.length()-1];

    if(c == 'e')s = "la";
    else if(c=='s')s = "les";
    else s = "le";

    cout<<verb<<"-tu "<<s<<" "<<noun<<" ?\n";

    return 0;
}