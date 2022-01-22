//https://dmoj.ca/problem/dpk
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

    int n, k;
    cin>>n>>k;

    vector<int>dp(k+1);

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i>=arr[j]){
                dp[i] = dp[i] || (!dp[i-arr[j]]);
            }
        }
    }

    if(dp[k])cout<<"First\n";
    else cout<<"Second\n";


    return 0;
}