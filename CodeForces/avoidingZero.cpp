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
        int sum = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum==0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(sum>0)sort(arr.begin(), arr.end(), greater<int>());
        else sort(arr.begin(), arr.end());
        
        for(auto x: arr){
            cout<<x<<" ";
        }
        cout<<"\n";


    }
    
    
    return 0;
}