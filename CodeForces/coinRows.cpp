//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        
        vector<vector<int>>arr(3, vector<int>(n+1));
        int mn = 1e18;
        int sum1 = 0;
        int sum2 = 0;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];
                if(i==1 && j>=2)sum1+=arr[i][j];
            }
        }

        if(n==1){
            cout<<0<<"\n";
            continue;
        }

        int l1 = 2;
        int l2 = 1;
        mn = min(mn, sum1);

        for(int i=1;i<n;i++){
            sum1-=arr[1][l1];
            sum2+=arr[2][l2];
            l1++;
            l2++;
            mn = min(mn, max(sum1, sum2));
        }

        cout<<mn<<"\n";


    }


    return 0;
}