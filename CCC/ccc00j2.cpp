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
    int ans = 0;
    for(int i=n;i<=m;i++){
        string s = to_string(i);
        int len = s.length();
        bool good = true;
        for(int j=0;j<(len+1)/2;j++){
            int cur = s[j] - '0';
            int nxt = s[len-j-1] - '0';

            if(cur == 0 && nxt == 0);
            else if(cur == 1 && nxt == 1);
            else if(cur == 8 && nxt == 8);
            else if(cur == 6 && nxt == 9);
            else if(cur == 9 && nxt == 6);
            else good = false;

        }
        if(good)ans++;
    }
    cout<<ans<<"\n";

    return 0;
}
