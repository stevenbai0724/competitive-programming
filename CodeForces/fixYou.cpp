//https://codeforces.com/problemset/problem/1391/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        int ans = 0;
        for(int i=1;i<=n;i++){
            string s; cin>>s;
            if(s[m-1]=='R')ans++;
            if(i==n){
                for(int j=1;j<=m;j++){
                    if(s[j-1]=='D')ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}