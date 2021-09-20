//https://codeforces.com/problemset/problem/1527/B1
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        string s; cin>>s;
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt++;

            }
        }
        if(!(cnt&1) || cnt==1)cout<<"BOB\n";
        else cout<<"ALICE\n";
        

    }


    return 0;
}