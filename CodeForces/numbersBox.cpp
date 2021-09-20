//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int n, m;
        cin>>n>>m;
        vector<vector<int>>arr(n+1, vector<int>(m+1));

        int num = 0;
        int sum = 0;
        int mn = 1e18;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
                if(arr[i][j]<0)num++;
                sum += abs(arr[i][j]);
                mn = min(mn, abs(arr[i][j]));
            }
        }

        if(num%2==0)cout<<sum<<"\n";
        else cout<<sum-mn-mn<<"\n";


    }


    return 0;
}