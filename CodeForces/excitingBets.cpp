//https://codeforces.com/problemset/problem/1543/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;

        if(a==b){
            cout<<"0 0\n";

        }
        else if(abs(a-b)==1){
            cout<<"1 0\n";
        }
        else{
            int diff = abs(a-b);
            int mx = max(a,b);
            int mn = min(a,b);

            int lower = (mn/diff)*diff;
            int higher = lower  + diff;
            if(abs(lower-mn) < abs(higher-mn)){
                cout<<diff<<" "<<abs(lower-mn)<<"\n";
            }  
            else{
                cout<<diff<<" "<<abs(higher-mn)<<"\n";
            }
        }
    }


    return 0;
}