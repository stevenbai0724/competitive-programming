//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int n; cin>>n;

        int p = 4*n;
        for(int i=1;i<=n;i++){
            cout<<p<<" ";
            p-=2;
        }
        cout<<"\n";


    }


    return 0;
}