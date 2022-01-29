//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);

    bool third = true;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i] > 2)third = false;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int h = (j-i+1)/2;

            map<int, int>mp;    
            int mx = 0;

            for(int k=i;k<=j;k++){
                mp[arr[k]]++;
                mx = max(mx, mp[arr[k]]);
            }
            if(mx > h){
                ans++;

            }
        }
    }
    cout<<ans<<"\n";



    return 0;
}
