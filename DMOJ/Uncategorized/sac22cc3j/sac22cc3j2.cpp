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

    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    if(y1 == y2)cout<<"x-axis\n";
    else if(x1 == x2)cout<<"y-axis\n";
    else cout<<"neither\n";

    return 0;
}
