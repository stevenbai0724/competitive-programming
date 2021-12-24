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


    vector<vector<int>>psa(32, vector<int>(2e5+1));
    for(int i=0;i<32;i++){
        for(int j=1;j<=2e5;j++){
            psa[i][j] = psa[i][j-1];
            if(!((1<<i)&j))psa[i][j]++;
        }
    }


    int t; cin>>t;


    while(t--){
        int l, r;
        cin>>l>>r;

        int ans = 1e18;

        for(int i=0;i<32;i++){
            int cnt = psa[i][r] - psa[i][l-1];
            ans = min(ans, cnt);
        }
        cout<<ans<<"\n";


    }

    return 0;
}