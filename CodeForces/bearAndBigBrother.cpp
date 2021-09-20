//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b;
    cin>>a>>b;
    int cnt = 0;
    while(a<=b){
        a*=3;
        b*=2; 
        cnt++;
    }
    cout<<cnt<<"\n";

    return 0;
}