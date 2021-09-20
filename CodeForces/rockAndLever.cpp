//https://codeforces.com/problemset/problem/1420/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        int p = 1;
        int ans = 0;
        for(int i=1;i<=30;i++){
            auto l = lower_bound(arr.begin(), arr.end(), p);
            auto r = upper_bound(arr.begin(), arr.end(), p*2-1);

            p*=2;

            ans += max((int)0, (int)(r-l-1)*(int)(r-l)/2);
        }
        cout<<ans<<"\n";



    }


    return 0;
}