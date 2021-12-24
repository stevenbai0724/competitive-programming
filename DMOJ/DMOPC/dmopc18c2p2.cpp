//
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

    int n, m, k;
    cin>>n>>m>>k;

    vector<int>arr(k);

    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    vector<int>top;

    for(int i=1;i<=(k-1+n)/n;i++){
        top.push_back(arr[i-1]);
    }   

    int ans = 0;
    int cur = 1;
    int ind = 0;

    for(int i=top.size();i<k;i++){
        ans += top[ind] - arr[i] + cur;
        cur++;
        if(cur >= n){
            cur = 1;
            ind++;
        }
    }
    cout<<ans<<"\n";


    return 0;
}