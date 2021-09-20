//
#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        string s; cin>>s;
        int mx = 1;

        for(char c: s){
            mx = max(mx, (int)c-48);
        }
        cout<<mx<<"\n";


    }

    return 0;
}