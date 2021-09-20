//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<double>arr(n+1);
        arr[0] = -1e18;
        double ans =-1e18;    
        double sum1 = 0;
        double sum2 = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            
        }
        sort(arr.begin(), arr.end());
        for(int i=1;i<=n;i++){
            sum1+=arr[i];
        }
        for(int i=1;i<n;i++){
            sum1-=arr[i];
            sum2+=arr[i];
            ans = max(ans, sum1/(n-i) + sum2/(i));
        }
        cout<<setprecision(20)<<ans<<"\n";


    }


    return 0;
}