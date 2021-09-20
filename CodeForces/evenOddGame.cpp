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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int alice = 0;
        int bob = 0;

        sort(arr.begin(), arr.end(), greater<int>());  
        
        for(int i=0;i<n;i++){
            if(!(i&1)){
                if(!(arr[i]&1))alice+=arr[i];
            }
            else{
                if(arr[i]&1)bob+=arr[i];
            }
        }
        if(alice>bob)cout<<"Alice\n";
        else if(bob>alice)cout<<"Bob\n";
        else cout<<"Tie\n";



    }

    return 0;
}