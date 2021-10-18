//https://dmoj.ca/problem/dmopc17c1p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<int>arr(n+1);
    vector<int>psa(n+1);
    gp_hash_table<int, int>mp;
    mp[0] = 1;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        psa[i] += arr[i];
    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        int val = psa[i]%m;
        ans += mp[val];
        mp[val]++;
    }
    cout<<ans<<"\n";


    


    return 0;
}