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

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<pair<int, int>>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i].first;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i].second;
        }
        sort(arr.begin(), arr.end());

        for(auto p: arr){
            int a = p.first;
            int b = p.second;
            if(k >= a){
                k += b;
            }
        }
        cout<<k<<"\n";
    }

    return 0;
}
