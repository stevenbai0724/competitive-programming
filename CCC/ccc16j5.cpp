//
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

    int n; cin>>n;
    vector<vector<int>>arr(2, vector<int>(n));

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());

    if(t==1){
        int ans = 0;

        for(int i=0;i<n;i++){
            ans += max(arr[0][i], arr[1][i]);
        }
        cout<<ans<<"\n";
    }
    else{
        int ans = 0;
        int R = n-1;
        for(int i=0;i<n;i++){
            ans += max(arr[0][i], arr[1][R]);
            R--;
        }
        cout<<ans<<"\n";
    }



    return 0;
}