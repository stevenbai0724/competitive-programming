//https://codeforces.com/problemset/problem/1593/A
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

    int t; cin>>t; 
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        cout<<max(max(b, c) - a + 1, (int)0)<<" "<<max(max(a, c) - b + 1, (int)0)<<" "<<max(max(b, a) - c + 1, (int)0)<<"\n";
    }


    return 0;
}