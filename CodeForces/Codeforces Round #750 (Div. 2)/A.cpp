//https://codeforces.com/contest/1582/problem/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;

        if((a+b+b+c+c+c)&1)cout<<1<<"\n";
        else cout<<0<<"\n";
    }



    return 0;
}