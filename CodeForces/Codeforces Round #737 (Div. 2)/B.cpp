//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, k;
        cin>>n>>k;
        assert(k<=n);

        vector<int>arr(n+1);
        vector<int>sorted(n+1);
        arr[0] = -1e18;
        sorted[0] = -1e18;
        

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sorted[i] = arr[i];
        }
        
        sort(sorted.begin(), sorted.end());

        int cnt = 1;
        for(int i=2;i<=n;i++){
            if(lower_bound(sorted.begin(), sorted.end(), arr[i])-lower_bound(sorted.begin(), sorted.end(), arr[i-1])==1)continue;
            cnt++;
        }
        if(cnt<=k)cout<<"Yes\n";
        else cout<<"No\n";

    }


    return 0;
}