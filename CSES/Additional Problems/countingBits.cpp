//https://cses.fi/problemset/task/1146
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int ans = 0;
    for(int cur = 0; ((int)1<<cur)<=n; cur++){

        int groups = (n+1) / ((int)1<<(cur));

        ans += ((int)1<<cur) * (groups/(int)2);        
             
        if(groups&1)ans += (n+1) % ((int)1<<cur);  
    }
    cout<<ans<<"\n";

    return 0;
}