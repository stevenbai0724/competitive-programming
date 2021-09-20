//https://codeforces.com/problemset/problem/266/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, t;
    cin>>n>>t;

    string s; cin>>s;

    while(t--){
        for(int i=0;i<n-1;i++){
            if(s[i]=='B' && s[i+1]=='G'){
                s[i] = 'G';
                s[i+1] = 'B';
                i++;
            }
        }
    }
    cout<<s<<"\n";


    return 0;
}