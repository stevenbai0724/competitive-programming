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

    int n; cin>>n;
    int sum = 0;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    if(sum&1){
        cout<<"Andrew is sad.\n";
        return 0;
    }
    int cur = 0;
    for(int i=1;i<=n;i++){
        cur += arr[i];
        if(cur == sum/2){
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"Andrew is sad.\n";

    return 0;
}
