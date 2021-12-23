//https://codeforces.com/contest/1610/problem/A
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
        int n, m;
        cin>>n>>m;
        if(n == 1 && m == 1)cout<<0<<"\n";
        else if(n == 1 || m==1) cout<<1<<"\n";
        else cout<<2<<"\n";
    }

    return 0;
}