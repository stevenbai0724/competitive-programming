//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);

        int cnt = 0;
        int mn = 1e18;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mn = min(mn, arr[i]);
        }
        for(int i=1;i<=n;i++){
            if(arr[i]==mn)cnt++;
        }
        cout<<n-cnt<<"\n";
        
    }
    

    return 0;
}