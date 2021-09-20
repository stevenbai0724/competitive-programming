//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = 0;
        vector<int>freq(101);
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            freq[x]++;
            ans = max(ans, freq[x]);
        }
        cout<<ans<<"\n";
    }
   
    return 0;

}