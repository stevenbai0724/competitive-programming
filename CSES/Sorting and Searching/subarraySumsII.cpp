//https://cses.fi/problemset/task/1661
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    map<int, int>mp;
    int sum = 0;
    mp[0] = 1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        sum += arr[i];
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout<<ans<<"\n";





    return 0;
}