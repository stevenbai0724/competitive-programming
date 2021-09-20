//https://codeforces.com/problemset/problem/1101/A

#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int l, r ,d;
        cin>>l>>r>>d;

        if(d<l){
            cout<<d<<"\n";
        }
        else{
            cout<<((r/d)+1)*d<<"\n";
        }

    }

    return 0;
}