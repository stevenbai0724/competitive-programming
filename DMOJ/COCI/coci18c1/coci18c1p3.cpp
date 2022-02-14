//https://dmoj.ca/problem/coci18c1p3
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

    int n, m;
    cin>>n>>m;
    vector<int>arr1(n+1), arr2(m+1);

    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    for(int i=1;i<=m;i++){
        cin>>arr2[i];
    }

    if(n > m){
        swap(n, m);
        swap(arr1, arr2);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());


    int L = -1;
    int R = 1e9+2;

    while(L + 1 < R){
        int maxDiff = (L+R)/2;

        int j = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            bool found = false;
            while(j<m){
                j++;
                if(abs(arr2[j] - arr1[i]) <= maxDiff){
                    found = true;
                    break;
                }
            }
            if(found)cnt++;
        }

        if(cnt == n)R = maxDiff;
        else L = maxDiff;
    }

    cout<<R<<"\n";

    

    return 0;
}