//https://codeforces.com/contest/1593/problem/C
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
        int n, k;
        cin>>n>>k;
        vector<int>arr(k);
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        int cat = 0;
        sort(arr.begin(), arr.end(), greater<int>());
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(cat>=arr[i])break;
            cnt++;
            cat += (n-arr[i]);
        }
        cout<<cnt<<"\n";
    }


    return 0;
}