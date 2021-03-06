//https://codeforces.com/problemset/problem/1592/B
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
        int n, x;
        cin>>n>>x;
        vector<int>sorted, arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sorted = arr;
        sort(sorted.begin(), sorted.end());

        for(int i=1;i<=n;i++){
            if(sorted[i] != arr[i]){
                int L = i-1;
                int R = n-L-1;
                if(L < x && R < x){
                    cout<<"NO\n";
                    goto nxt;
                }
            }
        }
        cout<<"YES\n";
        nxt:;



    }

    return 0;
}
