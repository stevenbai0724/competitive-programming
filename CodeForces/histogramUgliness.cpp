//https://codeforces.com/problemset/problem/1534/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+2);
        int sum = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        for(int i=1;i<=n;i++){
            if((arr[i]>arr[i-1] && arr[i]>arr[i+1])){
                int mx = max(arr[i-1], arr[i+1]);
                sum += (arr[i]-mx);
                arr[i] = mx;
            }
            sum += abs(arr[i]-arr[i-1]);
        }
        sum += arr[n];
        
        cout<<sum<<"\n";
    }




    return 0;
}