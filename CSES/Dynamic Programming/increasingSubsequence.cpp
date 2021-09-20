//https://cses.fi/problemset/task/1145
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(2e5+2, 1e18);
    arr[0] = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), x);
        int index = it - arr.begin();
        arr[index] = x;
    }
    int ans=  0;
    for(int i=1;i<=n;i++){
        if(arr[i]!=1e18)ans++;
    }
    cout<<ans<<"\n";
   
    return 0;

}