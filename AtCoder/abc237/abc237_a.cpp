//https://atcoder.jp/contests/abc237/tasks/abc237_a
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

    int n; cin>>n;

    int x = 1;
    for(int i=1;i<=31;i++){
        x *= 2;
    }

    if(n >= -x && n <= x-1)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
