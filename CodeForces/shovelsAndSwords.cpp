//https://codeforces.com/problemset/problem/1366/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<min(a,min(b,(a+b)/3))<<"\n";
    }

    return 0;
}