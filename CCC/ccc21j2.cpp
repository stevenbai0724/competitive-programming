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

    int n; cin>>n;
    string s;
    int mx = 0;

    for(int i=1;i<=n;i++){
        string name; cin>>name;
        int x; cin>>x;
        if(x > mx){
            s = name;
            mx = x;
        }
    }
    cout<<s<<"\n";

    return 0;
}