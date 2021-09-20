//https://codeforces.com/problemset/problem/1257/C
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin>>t;

    while(t--){
        map<int, int>mp;
        int ans = 1e18;
        int n; cin>>n;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(mp[x]==0)mp[x] = i;
            else{
                ans = min(ans, i-mp[x]+1);
                mp[x] = i;
            }
        }
        if(ans==1e18)cout<<"-1\n";
        else cout<<ans<<"\n";

    }
    return 0;
}