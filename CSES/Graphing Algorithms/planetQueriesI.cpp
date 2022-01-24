//https://cses.fi/problemset/task/1750
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

    int n, q;
    cin>>n>>q;
    vector<vector<int>>dp(31, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        cin>>dp[0][i];
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    while(q--){
        int x, k;
        cin>>x>>k;
        if(k == 0)cout<<x<<"\n";
        else{
            int ans = x;

            for(int i=0;i<=30;i++){
                if((1<<i)&k){
                    ans = dp[i][ans];
                }
            }
            cout<<ans<<"\n";
        }
    }

    return 0;
}
