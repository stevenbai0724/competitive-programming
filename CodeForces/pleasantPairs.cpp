//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<pair<int, int>>arr(n+1);

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            arr[i] = {x, i};

        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(arr[j].first*arr[i].first>(2*n))break;
                if(arr[i].first*arr[j].first == arr[i].second + arr[j].second)ans++;
            }   
        }
        cout<<ans<<"\n";
        


    }


    return 0;
}