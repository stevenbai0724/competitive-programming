//https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int ans = arr[1];
    int sum = 0;

    for(int i=1;i<=n;i++){
        if(sum < 0)sum = 0;
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout<<ans<<"\n";


    return 0;
}