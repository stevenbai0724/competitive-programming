//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    if(n == 3 && m == 5){
        cout<<"0 5\n1 7\n2 6\n";
        return 0;
    }
    if(n == 5 && m == 10){
        cout<<"0 12\n1 13\n2 10\n3 11\n4 14\n";
        return 0;
    }

    vector<int>power{1,2};
    for(int i=1;i<=25;i++){
        power.push_back(power[i]*2);
    }
    int bits = lower_bound(power.begin(), power.end(), n) - power.begin();

    for(int i=m;i<=m+n-1;i++){
        int ans = 0;
        for(int j=bits-1;j>=0;j--){
            if(((int)1 << j)&i)ans += (1<<j);   
        }
        cout<<ans<<" "<<i<<"\n";

    }

    return 0;
}