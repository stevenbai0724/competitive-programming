#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    int mx = 0;
    int mn = 1e9;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    if(count(arr.begin(), arr.end(), mx)==n){
        cout<<0<<" "<<(n*(n-1))/2<<"\n";
        return 0;
    }
    
    cout<<mx-mn<<" "<<count(arr.begin(), arr.end(), mx) * count(arr.begin(), arr.end(), mn)<<"\n";

    return 0;

}