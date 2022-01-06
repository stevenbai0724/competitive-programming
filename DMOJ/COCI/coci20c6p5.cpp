//https://dmoj.ca/problem/coci20c6p5
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

    int n, q;
    cin>>n>>q;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    while(q--){
        int x, y;
        cin>>x>>y;
        int L = 1;
        int R = y-x+2;

        while(L+1<R){
            int m = (L+R)/2;
            int cnt = 0;
            for(int i=x;i<=y;i++){
                if(arr[i] >= m)cnt++;
            }
            if(cnt >= m)L = m;
            else R = m;
        }
        cout<<L<<"\n";
    }

    return 0;
}
