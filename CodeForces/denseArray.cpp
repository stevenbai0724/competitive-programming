//https://codeforces.com/problemset/problem/1490/A
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
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            int mn = min(arr[i], arr[i+1]);
            int mx = max(arr[i], arr[i+1]);
            while(mn*2<mx){   
                mn*=2;
                ans ++ ;
            }
        }
        cout<<ans<<"\n";
    }




    return 0;
}