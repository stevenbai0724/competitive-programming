//https://cses.fi/problemset/task/1630
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n,ans = 0, time =0;
    cin>>n;
    vector<pair<int, int>>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(), arr.end());
    for(auto x: arr){
        time+=x.first;
        ans += (x.second-time);
    }
    cout<<ans<<"\n";

    return 0;
}