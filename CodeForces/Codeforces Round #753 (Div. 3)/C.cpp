//https://codeforces.com/contest/1607/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        if(n==1){
            cout<<arr[0]<<"\n";
            continue;
        }
        int sub = arr[0];
        int ans = arr[0];

        for(int i=1;i<n;i++){
            arr[i] -= sub;
            ans = max(ans, arr[i]);
            sub += arr[i];
        }

        cout<<ans<<"\n";


    }


    return 0;
}