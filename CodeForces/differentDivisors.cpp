//https://codeforces.com/contest/1474/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        int d; cin>>d;
        int p = 1;
        for(int i=1+d;i<=1e5+7;i++){
            if(prime(i)){
                p*=i;
                break;
            }
        }
        for(int i=p+d;i<=2e5+1e4;i++){
            if(prime(i)){
                p*=i;
                break;
            }
        }
        cout<<p<<"\n";

    }
    return 0;
}