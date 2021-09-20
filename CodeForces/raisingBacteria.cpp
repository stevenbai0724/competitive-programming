//https://codeforces.com/problemset/problem/579/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x; cin>>x;
    int ans = 0;

    while(x>0){
        if(x&1)ans++;
        x>>=1;
    }
    cout<<ans<<"\n";


    return 0;
}