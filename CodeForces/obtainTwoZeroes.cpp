//https://codeforces.com/problemset/problem/1260/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        int a, b;
        cin>>a>>b;

        if(a>b)swap(a,b);

        if((a+b)%3 == 0 && 2*a >= b){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        
    }

    return 0;
}