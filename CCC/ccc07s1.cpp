//https://dmoj.ca/problem/ccc07s1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_Node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int y, m, d;
        cin>>y>>m>>d;
        if(y < 1989)cout<<"Yes\n";
        else if(y > 1989)cout<<"No\n";
        else {
            if(m < 2)cout<<"Yes\n";
            else if(m > 2)cout<<"No\n";
            else{
                if(d <= 27)cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }

    return 0;
}
