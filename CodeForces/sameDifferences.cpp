//https://codeforces.com/contest/1520/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define string std::string
#define int long long
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];

        }
        int ans = 0;
        map<int, int>start;

        for(int i=1;i<=n;i++){
            
            ans+=start[arr[i]-i];
            start[arr[i]-i]++;
        }

        cout<<ans<<"\n";
        

    }

    return 0;
}