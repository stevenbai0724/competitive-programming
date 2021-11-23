//https://codeforces.com/problemset/problem/1594/B
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

        vector<bool>use(31);

        for(int i=0;i<=30;i++){
            if((1<<i)&k)use[i] = true; 
        }
        int ans = 0;
        for(int i=0;i<=30;i++){
            if(use[i]){
                int p = 1;
                for(int j=1;j<=i;j++){
                    p*=n;
                    p%= (int)1e9+7;
                }
                ans += p;
                ans %=(int)1e9 + 7;
            }
            
        }
        cout<<ans<<"\n";

    }

    return 0;
}