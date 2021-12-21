//https://dmoj.ca/problem/bobhatestriangles
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

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        if(x > y)swap(x,y);
        cout<<x<<" "<<y<<"\n";
    }

    return 0;
}