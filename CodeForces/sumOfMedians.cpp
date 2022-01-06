//https://codeforces.com/problemset/problem/1440/B
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

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        int sum = 0;

        vector<int>arr(n*k+1);

        for(int i=1;i<=n*k;i++){
            cin>>arr[i];
        }
        int inc = n/2;
        inc++;
        int cnt = 1;
        for(int i=n*k+1-inc;cnt<=k;cnt++, i-=inc){
            sum += arr[i];
        }

        cout<<sum<<"\n";
    }

    return 0;
}
