//https://codeforces.com/contest/1476/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        double n, k;
        cin>>n>>k;
        double cf = ceil(n/k);
        cout<<setprecision(18)<<ceil((cf * k)/n)<<"\n";
    }   

 
}