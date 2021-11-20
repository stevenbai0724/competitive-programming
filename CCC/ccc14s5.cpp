//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
int n; 
int solve(int deep, int use, int cur, vector<pair<int, int>>arr, vector<int>dp){
    if(dp[use])return dp[use];
    int x = arr[use].first;
    int y = arr[use].second;
    int mx = deep;
    for(int i=1;i<=n;i++){  
        if(i==use)continue;
        int dis = (abs(arr[i].first - x)*abs(arr[i].first - x)) + (abs(arr[i].second - y)*abs(arr[i].second - y));
        if(dp[i]){
            mx = max(mx, dp[i]);
            continue;
        }
        if(dis < cur){
            mx = max(mx, solve(deep+1, i, dis, arr, dp));
        }
    }
    dp[use] = mx;
    deep = mx;
    return deep;
    
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

   cin>>n;

    vector<pair<int, int>>arr{{0,0}};

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    vector<int>dp(n+1);
    cout<<solve(0,0,1e18,arr,dp)<<"\n";



    return 0;
}