//https://dmoj.ca/problem/binoculars
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

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);
    vector<int>ans(n+1);
    int cnt = 0;
    while(k--){
        int a, b, x;
        cin >> a >> b >>x;
        cnt += max((int)0, x- arr[a]);
        ans[a] += max((int)0, x - arr[a]);
        arr[a] += max((int)0, x- arr[a]);
        
        arr[a] -= x;
        arr[b] += x;
        
    }
    cout<<cnt<<"\n";

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


    return 0;
}