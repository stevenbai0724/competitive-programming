//https://codeforces.com/problemset/problem/1418/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int unsigned long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int x, y, k;
        cin>>x>>y>>k;

        cout << (y*k + k -1 + x -2)/(x-1) + k<<"\n";
    }

    return 0;
}
