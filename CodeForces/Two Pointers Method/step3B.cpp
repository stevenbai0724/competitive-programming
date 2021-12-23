//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
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
    int sum = 0;

    int j = 0;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i > 1){
            sum -= arr[i-1];
        }
        if(j < i){
            j = i;
            sum = arr[i];
        }


        while(j<n && sum + arr[j+1] <= k){
            j++;
            sum += arr[j];
        }
        if(sum > k)continue;

        int len = j-i+1;

        ans += (len)*(len+1)/2;

    }
    cout<<ans<<"\n";

    return 0;
}