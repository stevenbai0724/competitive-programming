//https://dmoj.ca/problem/bbc08d
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

    cout<<2000<<"\n";
    for(int i=1;i<=1000;i++){
        cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n";
    }
    for(int i=1000;i>=1;i--){
        cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n";
    }

    return 0;
}