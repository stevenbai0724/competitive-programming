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

    int n, m;
    cin>>n>>m;

    int cnt = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+j == 10)cnt++;
        }
    }
    if(cnt == 1){
        cout<<"There is 1 way to get the sum 10.\n";
    }
    else cout<<"There are "<<cnt<<" ways to get the sum 10.\n";

    return 0;
}