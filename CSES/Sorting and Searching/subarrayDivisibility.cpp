//https://cses.fi/problemset/task/1662
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1), psa(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]%=n;
        if(arr[i]<0)arr[i] += n;
        psa[i] = psa[i-1]+arr[i];
    }

    map<int, int>mp;
    mp[0] = 1;

    for(int i=1;i<=n;i++){
        mp[psa[i]%n]++;
    }

    int ans = 0;
    
    for(int i=0;i<=n;i++){
        ans += mp[i]*(mp[i]-1)/2;
    }
    cout<<ans<<"\n";






    return 0;
}