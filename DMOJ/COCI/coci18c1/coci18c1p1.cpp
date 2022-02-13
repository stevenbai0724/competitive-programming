//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int k, n;
    cin>>k>>n;

    if(n == 1)cout<<k<<"\n";
    else {
        for(int i=1;i<n;i++){
            cout<<i<<"\n";
            k -= i;
        }
        cout<<k<<"\n";
    }


    return 0;
}