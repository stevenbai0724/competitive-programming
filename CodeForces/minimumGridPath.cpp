//https://codeforces.com/problemset/problem/1499/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        int sum1 = arr[1], sum2 = arr[2];

        int ans = (arr[1] * n) + (arr[2] * n);

        int mn1 = arr[1];
        int mn2 = arr[2];

        int cnt1 = 1;
        int cnt2 = 1;


        for(int i=3;i<=n;i++){
            if(i&1){
                cnt1++;
                mn1 = min(mn1, arr[i]);
                sum1 += arr[i];


            }
            else{
                cnt2++;
                mn2 = min(mn2, arr[i]);
                sum2 += arr[i];
            }
            
            int vert = (sum1 - mn1) + (n-(cnt1-1))*mn1;
            int horz = (sum2 - mn2) + (n-(cnt2-1))*mn2;
            ans = min(ans, vert+horz);
        }
        cout<<ans<<"\n";

    }


    return 0;
}