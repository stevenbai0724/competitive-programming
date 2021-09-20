//https://codeforces.com/problemset/problem/344/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    int cnt = 0;
    string cur = "";
    for(int i=1;i<=t;i++){
        string s; cin>>s;
        if(i==1){
            cur = s;
            cnt++;
            continue;
        }
        if(s!=cur){
            cur = s;
            cnt++;
        }
    }
    cout<<cnt<<"\n";


    return 0;
}