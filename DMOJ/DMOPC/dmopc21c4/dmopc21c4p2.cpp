//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
    sort(arr.begin(), arr.end());

    vector<bool>vis(5e6+4);

    int cnt = 0;

    for(int i=1;i<=n;i++){
        if(!vis[arr[i]]){
            vis[arr[i]] = true;
            cnt++;
            for(int j=2;j*arr[i]<=5e6;j++){
                vis[j*arr[i]] = true;
            }
        }
    }
    cout<<cnt<<"\n";

    return 0;
}