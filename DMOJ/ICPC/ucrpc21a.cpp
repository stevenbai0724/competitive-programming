//https://dmoj.ca/problem/ucrpc21a
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

    int ans = 0;

    int n, m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1] == 't')ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
