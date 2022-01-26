//https://atcoder.jp/contests/abc167/tasks/abc167_d
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
int ln = 61;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    vector<vector<int>>dp(ln, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        cin>>dp[0][i];
    }

    for(int i=1;i<ln;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    int ans = 1;

    for(int i=0;i<ln;i++){
        if(((int)1<<i)&k){
            ans = dp[i][ans];
        }
    }
    cout<<ans<<"\n";

    return 0;
}
