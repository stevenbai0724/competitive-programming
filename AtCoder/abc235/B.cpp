//https://atcoder.jp/contests/abc235/tasks/abc235_b
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

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = n;
    for(int i=1;i<n;i++){
        if(arr[i+1] > arr[i])continue;
        else{
            ans = i;
            break;
        }
    }
    cout<<arr[ans]<<"\n";

    return 0;
}
