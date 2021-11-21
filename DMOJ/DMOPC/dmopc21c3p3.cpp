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
    int n, m;
    cin>>n>>m;
    cout<<m+m+1<<"\n";

    cout<<0<<"\n";


    for(int i=2;i<=m+1;i++){
        cout<<i<<"\n"<<i-1<<"\n";
    }

    return 0;
}