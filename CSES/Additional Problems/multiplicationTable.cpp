//https://cses.fi/problemset/task/2422
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

    int n; cin>>n;

    int R = 1e12;
    int L = 0;

    while(L+1<R){
        int m = (L+R)/2;
        int more = 0;
        int less = 0;
        int equal = 0;

        for(int i=1;i<=n;i++){
            more += max((int)0, (i*n - m + i - 1)/i);
            less += min((m-1)/i, n);
        }
        equal = n*n - (more + less);
        if(less + equal< (n*n)/2 + 1)L = m;
        else R = m;

    }
    cout<<R<<"\n";
    

    return 0;
}