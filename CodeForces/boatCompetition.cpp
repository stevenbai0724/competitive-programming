//https://codeforces.com/problemset/problem/1399/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);
        int sum = 0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sum+= arr[i];
        }
        sort(arr.begin(), arr.end());

        for(int i=1;i<=sum;i++){    
            int l = 1;
            int r = n;
            int count = 0;
            while(l<r){
                if(arr[l]+arr[r]<i)l++;
                else if(arr[l]+arr[r]>i)r--;
                else{
                    count++;
                    l++;
                    r--;
                }
            }
            ans= max(ans, count);

        }
        cout<<ans<<"\n";

    

}

return 0;
}