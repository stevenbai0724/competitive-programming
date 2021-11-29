//https://codeforces.com/gym/102951/problem/B
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
 
    int n, s;
    cin>>n>>s;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
 
    sort(arr.begin(), arr.end());
 
    int sum = 0;
    int j = 0;
    while(j<n && sum + arr[j+1] <= s){
        j++;
        sum += arr[j];
    }
    cout<<j<<"\n";
 
    return 0;
}