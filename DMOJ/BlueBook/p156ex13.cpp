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
    int mxn = 1e5;
    vector<bool>prime(mxn+1, true);

    for(int i=2;i*i<mxn;i++){
        if(prime[i]){
            for(int j=2;j*i<=mxn;j++){
                prime[i*j] = false;
            }
        }
    }
    vector<int>nums{0};
    for(int i=2;i<=mxn;i++){
        if(prime[i])nums.push_back(i);
    }
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cout<<nums[i];
        if(i%10 == 0)cout<<"\n";
        else cout<<" ";
    }
    if(n%10 != 0)cout<<"\n";
    return 0;
}
