//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int unsigned long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int>arr(32);
    vector<int>psa(32);

    for(int i=1;i<=31;i++){
        int cur = pow(2,i);
        arr[i] = (cur)*(cur-1)/2;
    }
    int sum = 0;
    for(int i=1;i<=31;i++){
        sum+=arr[i];
        psa[i] = sum;
    }
    int t; cin>>t;

    while(t--){
        int x; cin>>x;

        cout<<upper_bound(psa.begin(), psa.end(), x)-psa.begin()-1<<"\n";

    }
    return 0;
}