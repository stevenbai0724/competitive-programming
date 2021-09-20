//https://codeforces.com/contest/1475/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int temp = n;
        bool found = false;
        
        while(true){
            temp-=2021;
            if(temp<0)break;
            if(temp%2020==0){
                cout<<"YES\n";
                found = true;
                break;
            }
        }
        if(found)continue;
        temp = n;
        while(true){
            temp-=2020;
            if(temp<0)break;
            if(temp%2021==0){
                cout<<"YES\n";
                found = true;
                break;
            }
        }   
        if(found)continue;
        cout<<"NO\n";

        
        
    }
   
    return 0;

}