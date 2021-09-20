//https://codeforces.com/contest/1551/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;

        if(n%3==0){
            cout<<n/3<<" "<<n/3<<"\n";
        }
        else if(n%3==1){
            cout<<n/3 +1<<" "<<n/3<<"\n";
        }
        else cout<<n/3<<" "<<n/3 + 1<<"\n";


    }


    return 0;
}