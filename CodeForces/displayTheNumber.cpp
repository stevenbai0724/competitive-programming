//https://codeforces.com/problemset/problem/1295/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        string s = "";

        if(n&1){
            s += '7';

            for(int i=1;i<=(n-3)/2;i++){
                s+='1';
            }
        }
        else{
            for(int i=1;i<=(n/2);i++){
                s+='1';
            }
        }
        cout<<s<<"\n";
        
    }

    return 0;   
}