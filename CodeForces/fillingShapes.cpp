#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int p = n/2;
    if(n%2==1) cout<<0;
    else cout<<(int)(pow(2, p));
    return 0;
}