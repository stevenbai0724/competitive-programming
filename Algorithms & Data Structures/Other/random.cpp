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
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    //print some numbers between [46,52];
    double average = 0;
    for(int i=1;i<=500000;i++){
        average+= rng()%7 + 46;
    }

    cout<<setprecision(20)<<average/500000.0<<"\n";



    return 0;
}
