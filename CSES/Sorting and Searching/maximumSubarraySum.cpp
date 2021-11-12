//https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;

    vector<int>arr(n+1);
    vector<int>psa(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        psa[i] += arr[i];
    }
    int mx = psa[1];
    int mn = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx, psa[i]-mn);
        mn = min(mn, psa[i]);
    }   
    cout<<mx<<"\n";


    return 0;
}