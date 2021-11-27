//https://dmoj.ca/problem/ppwindsor18p7
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

    vector<int>dp(n+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        for(int j=i;j<=n;j++){
            dp[j] = max(dp[j-i] + x, dp[j]);
        }
    }
    cout<<dp[n]<<"\n";


    return 0;
}