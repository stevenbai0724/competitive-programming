//https://codeforces.com/contest/1607/problem/B
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
        int a, b;
        cin>>a>>b;
        int mod = b%4;
        if(a&1){
            if(mod==1){
                cout<<b+a<<"\n";
            }
            else if(mod==2){
                cout<<a-1<<"\n";
            }
            else if(mod==3){
                cout<<a-1-b<<"\n";
            }
            else cout<<a<<"\n";
        }else{
            if(mod==1){
                cout<<a-b<<"\n";
            }
            else if(mod==2){
                cout<<a+1<<"\n";
            }
            else if(mod==3){
                cout<<b+1+a<<"\n";
            }
            else cout<<a<<"\n";
        }
    }


    return 0;
}