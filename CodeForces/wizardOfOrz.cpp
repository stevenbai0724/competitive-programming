//https://codeforces.com/contest/1467/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string ans = "989";
        if(n==1){
            cout<<9<<"\n";
            continue;
        }
        if(n==2){
            cout<<98<<"\n";
            continue;
        }
        if(n==3){
            cout<<989<<"\n";
            continue;
        }
        for(int i=0;i<n-3;i++){
            ans+=to_string(i%10);
        }
        cout<<ans<<"\n";
    }
    
    return 0;

}