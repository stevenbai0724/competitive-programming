//https://codeforces.com/contest/1614/problem/A
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

    int t; cin>>t;
    while(t--){
        int n, l, r, k;
        cin>>n>>l>>r>>k;

        vector<int>arr;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(x>=l && x<=r)arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int x: arr){
            if(k >= x){
                k -= x;
                cnt++;
            }
            else break;
        }
        cout<<cnt<<"\n";
    }

    return 0;
}