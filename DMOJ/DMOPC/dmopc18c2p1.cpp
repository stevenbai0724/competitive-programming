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

    int p; cin>>p;
    int mxY = -1e18;
    int mxX = -1e18;
    int mnY = 1e18;
    int mnX = 1e18;

    while(p--){
        int x, y;
        cin>>x>>y;
        mxY = max(mxY, y);
        mxX = max(mxX, x);
        mnY = min(mnY, y);
        mnX = min(mnX, x);
    }
    cout<<((mxX - mnX)*2 + (mxY - mnY)*2)<<"\n";

    return 0;
}