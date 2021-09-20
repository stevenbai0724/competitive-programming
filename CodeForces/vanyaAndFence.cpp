//https://codeforces.com/problemset/problem/677/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    int ans = n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x>m)ans++;
    }
    cout<<ans<<"\n";

    return 0;
}