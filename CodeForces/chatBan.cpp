//https://codeforces.com/problemset/problem/1612/C
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
        int k, x;
        cin>>k>>x;

        int L = 0;
        int R = 2*k-1;
        //binary search on messages sent, which is monotonic
    
        while(L+1<R){
            int m = (L+R)/2;
            int cnt = 0;

            if(m <= k)cnt = m*(m+1)/2;
            else {
                cnt = k * (k+1) / 2;
                cnt += ((k-1)*(k)/2) - ((2*k - m)*(2*k - m-1)/2);
            }
      
            if(cnt >= x){
                R = m;
            }
            else L = m;
        }
        cout<<R<<"\n";
    }

    return 0;
}