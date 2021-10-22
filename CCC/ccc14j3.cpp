//https://dmoj.ca/problem/ccc14j3
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
    int A = 100, B = 100;

    while(t--){
        int x, y;
        cin>>x>>y;
        if(x>y)B-=x;
        if(y>x)A-=y;
    }
    cout<<A<<"\n"<<B<<"\n";

    return 0;
}