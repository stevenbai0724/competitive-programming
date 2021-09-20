//https://codeforces.com/contest/1471/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int sum = 0;
        int hi = 0;

        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]%x==0)hi+=arr[i]/x;
            else hi+=arr[i]/x +1;
        }
        if(sum%x==0)sum/=x;
        else sum = sum/x + 1;

        cout<<sum<<" "<<hi<<"\n";
    }

    return 0;
}