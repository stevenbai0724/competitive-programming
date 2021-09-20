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

        vector<int>arr(n);
        vector<int>pma(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }  
        
        sort(arr.begin(), arr.end());

        int mn = 1e18;

        for(int i=0;i<n-1;i++){
            mn = min(mn, arr[i+1]-arr[i]);
            pma[i] = mn;
        }

        for(int i=n-1;i>0;i--){
            if(arr[i]<=pma[i-1]){
                cout<<i+1<<"\n";
                goto nxt;
            }
        }
        cout<<1<<"\n";
        nxt:;


    }

    return 0;
}