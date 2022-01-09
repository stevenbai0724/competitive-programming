//https://dmoj.ca/problem/ucrpc21b
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

    vector<int>arr{0,1,2,3,4,5};

    int n; cin>>n;

    while(n--){
        int x, y;
        cin>>x>>y;
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    for(int i=1;i<=5;i++){
        if(arr[i] == 3)cout<<i<<"\n";
    }

    return 0;
}
