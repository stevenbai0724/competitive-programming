//https://dmoj.ca/problem/si17c1p6
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

    int n, t;
    cin>>n>>t;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        assert(arr[i] >= 0);
    }

    int L = 1;
    int R = 1e12+1;

    while(L + 1 < R){
        int m = (L+R)/2;
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(arr[i] < m)sum += m - arr[i];
        }

        if(sum <= t)L = m;
        else R = m;
    }
    cout<<L<<"\n";

    

    return 0;
}
