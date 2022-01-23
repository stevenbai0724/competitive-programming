//https://cses.fi/problemset/task/1745
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

    int n; cin>>n;
    int sum = 0;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    vector<bool>dp1(sum+1), dp2(sum+1), temp(sum+1);

    for(int i=1;i<=n;i++){
        int val = arr[i];
        dp2[val] = true;

        for(int j=1;j<=sum;j++){
            if(dp1[j]) dp2[j] = true;
            if(j > val){
                if(dp1[j-val]) dp2[j] = true;
            }
        }

        dp1 = dp2;
        dp2 = temp;
    }
    cout<<count(dp1.begin(), dp1.end(), true)<<"\n";
    for(int i=1;i<=sum;i++){
        if(dp1[i])cout<<i<<" ";
    }
    cout<<"\n";


    return 0;
}
