//https://dmoj.ca/problem/2spooky4me
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

    int n, l, s;
    cin>>n>>l>>s;
    vector<pair<int, int>>arr;

    for(int i=1;i<=n;i++){
        int a, b, x;
        cin>>a>>b>>x;
        b = min(b, l);
        if(a>l)continue;
        arr.push_back({a,x});
        arr.push_back({b+1,-x});
    }

    arr.push_back({1,0});
    arr.push_back({l+1, 0});

    sort(arr.begin(), arr.end());

    int len = arr.size();
    int val = 0;
    int ans = 0;

    for(int i=0;i<len-1;i++){
        val +=arr[i].second;
        if(val<s){
            ans += arr[i+1].first - arr[i].first;
        }
    }
    cout<<ans<<"\n";





    return 0;
}