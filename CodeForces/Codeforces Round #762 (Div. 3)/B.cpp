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
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int cnt = 0;

        int L = 1;
        int R = 32592;
        while(L+1 < R){
            int m = (L+R)/2;
            if(m*m <= n)L = m;
            else R = m;
        }
        cnt += L;

        L = 1;
        R = 1001;

        while(L+1<R){
            int m = (L+R)/2;
            if(m*m*m <= n)L = m;
            else R = m;
        }
        cnt += L;

        L = 1;
        R = 32;

        while(L+1 < R){
            int m = (L+R)/2;
            if(m*m*m*m*m*m <= n)L = m;
            else R = m;
        }
        cnt -= L;

        cout<<cnt<<"\n"; 

        
    }

    return 0;
}