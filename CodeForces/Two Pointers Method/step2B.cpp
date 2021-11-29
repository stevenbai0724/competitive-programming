//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
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

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int j = 1;
    int sum = arr[1];
    int mn = 1e18;
    for(int i=1;i<=n;i++){
        if(i>1){
            sum -= arr[i-1];
        }
        if(j<i){
            j = i;
            sum = arr[j];
        }
        while(j<n && sum < k){
            j++;
            sum+=arr[j];
        }
        if(sum >= k)mn = min(mn, j-i+1);
        
    }
    cout<<(mn == 1e18 ? -1 : mn)<<"\n";

    return 0;
}