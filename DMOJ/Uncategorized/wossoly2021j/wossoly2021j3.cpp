//
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
    //1 5 10 50 100 500 1000

    vector<int>arr(8);

    arr[7] = n/1000;
    n%=1000;
    arr[6] = n/500;
    n%=500;
    arr[5] = n/100;
    n%=100;
    arr[4] = n/50;
    n%=50;
    arr[3] = n/10;
    n%=10;
    arr[2] = n/5;
    n%=5;
    arr[1] = n;

    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}