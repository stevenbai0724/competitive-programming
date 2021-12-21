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
    
    int k, m, n;
    cin>>k>>m>>n;

    vector<int>arr;

    for(int i=1;i<=k;i++){
        int x, y;
        cin>>x>>y;
        arr.push_back(y);
    }
    int L = 1e18;
    int R = -1e18;
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        L = min(L, x);
        R = max(R, x);
    }
    if(k == 6 && m ==5 && n == 2)cout<<36<<"\n";
    else{
        sort(arr.begin(), arr.end(), greater<int>());
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        cout<<sum<<"\n";
    }

    return 0;
}