//
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

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());

        int L = 0;
        int R = 1e18;

        while(L+1 < R){
            int m = (L+R)/2;
            int cnt = m;
            for(int i=0;i<n-1;i++){
                if(arr[i] + m -1 < arr[i+1]){
                    cnt += m;
                }
                else{
                    cnt += arr[i+1] - arr[i];
                }
            }
            if(cnt >= k)R = m;
            else L = m;

        }
        cout<<R<<"\n";


    }


    return 0;
}