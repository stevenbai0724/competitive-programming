//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    if(n%5==0)cout<<n/5<<"\n";
    else cout<<n/5  + 1 <<"\n";


    return 0;
}