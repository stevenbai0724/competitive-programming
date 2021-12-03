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

    int x = 0;
    int y = 0;
    int aim = 0;

    while(true){
        string s; cin>>s;
        if(s == "stop")break;
        else if(s == "forward"){
            int n; cin>>n;
            x += n;
            y += aim * n;
        }
        else if(s == "down"){
            int n; cin>>n;
            aim += n;
        }
        else {
            int n; cin>>n;
            aim -= n;
        }
    }
    cout<<x*y<<"\n";
    return 0;
}