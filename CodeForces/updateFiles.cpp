//https://codeforces.com/problemset/problem/1606/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr(61);
    arr[1] = 2;
    arr[0] = 1;
    for(int i=2;i<=60;i++){
        arr[i] = arr[i-1]*2;
    }
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(n==1){
            cout<<0<<"\n";
            continue;
        }

        auto it = upper_bound(arr.begin(), arr.end(), k);
        it--;
        int ind = it-arr.begin();
        int total = 1;
        int cnt = 0;
        for(int i=0;i<=ind;i++){
            cnt++;
            total += arr[i];
            if(total>=n)break;
        }
        
        if(total<n){
            cnt += (n-total+k-1)/k;
        }
        cout<<cnt<<"\n";

    }


    return 0;
}