//https://dmoj.ca/problem/checknum
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
int getNum(int n){

    int L = 1;
    int R = 1e10;

    while(L+1 < R){
        int m = (L+R)/2;
        if(m*m <= n)L = m;
        else R = m;
    }

    return L;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

            int SQ = getNum(n);
            int ans = 1e18;
            for(int i=max((int)1, SQ-10); i <= SQ+10; i++){
                if(i*i > n)break;
                int L = i*i;
                int R = n - L;
       
                int a = (i+8)/9;
                int b = (R+8)/9;
                if(a > b){
                    ans = min(ans, a + a -1);
                }
                else{
                    ans = min(ans, b + b);
                }

            }
            cout<<ans<<"\n";
     
    }

    return 0;
}