//https://dmoj.ca/problem/noip18p2
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);
        vector<bool>dp(25001), have(25001);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            have[arr[i]] = true;
        }

        for(int i=1;i<=25000;i++){
            for(int j=1;j<=n;j++){
                if(arr[j] == i || arr[j]>i)continue;
                if(dp[i-arr[j]] || have[i-arr[j]])dp[i] = true;
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!dp[arr[i]])ans ++ ;
        }
        cout<<ans<<"\n";



    }

    return 0;
}