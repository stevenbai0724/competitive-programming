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


    int n, q;
    cin>>n>>q;
    vector<int>lcm(n+1);
    lcm[0] = 1;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        lcm[i] = lcm[i-1]*x/(__gcd(x, lcm[i-1]));
        if(lcm[i] > 1e9)lcm[i] = 1e9+7;
    }

    while(q--){
        int t; cin>>t;
        int L = -1;
        int R = n+1;

        while(L+1<R){
            int mid = (L+R)/2;

            if(t % lcm[mid] == 0)L = mid;
            else R = mid;
        }
        if(R == n+1)cout<<-1<<"\n";
        else cout<<R<<"\n";
    }


    return 0;
}   