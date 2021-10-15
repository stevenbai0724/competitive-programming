//https://dmoj.ca/problem/dmopc21c2p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, h, p;
    cin>>n>>h>>p;
    vector<int>arr(n+1);
    vector<int>psa(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i=1;i<=n;i++){
        psa[i] = psa[i-1];
        psa[i] += arr[i];
    }


    int ans = psa[n]*p;

    for(int i=1;i<=n;i++){
        int cnt = arr[i] * h;
        cnt+=max((psa[n]-psa[i]-(arr[i]*(n-i))), (int)0)*p;
        ans = min(ans, cnt);

    }

    cout<<ans<<"\n";

 






    return 0;
}