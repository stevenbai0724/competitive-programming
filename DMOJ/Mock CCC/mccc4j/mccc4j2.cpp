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

    int n, a, b;
    cin>>n>>a>>b;
    int x =0;
    int y=0;

    for(int i=1;i<=n;i++){
        int c, d;
        cin>>c>>d;
        if(c < a)x++;
        else x += 2;

        if(d < b)y++;
        else y+=2;
    }

    if(x < y)cout<<"Andrew wins!\n";
    else if(y < x)cout<<"Tommy wins!\n";
    else cout<<"Tie!\n";

    return 0;
}
