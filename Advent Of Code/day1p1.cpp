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

    int cnt = 0;
    int prev = -1;
    while(true){
        int x; cin>>x;

        if(prev == -1){
            prev = x;
            continue;
        }

        if(x>prev)cnt++;

        prev = x;
        
        if(x == 5881)break;
    }

    cout<<cnt<<"\n";

    return 0;
}