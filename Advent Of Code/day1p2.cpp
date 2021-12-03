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

    vector<int>arr{0};

    while(true){
        int x; cin>>x;
        arr.push_back(x);
        if(x==5881)break;
    }

    int n = arr.size()-1;
    int prev = arr[1] + arr[2] + arr[3];
    int sum = prev;
    int cnt = 0;
    for(int i=4;i<=n;i++){
        sum += arr[i];
        sum -= arr[i-3];
        if(sum > prev)cnt++;
        prev = sum;
    }
    cout<<cnt<<"\n";

    return 0;
}