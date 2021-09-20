//https://codeforces.com/problemset/problem/1542/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin>>t;

    while(t--){
     
        int n; cin>>n;

        int cnt = 0;
        for(int i=1;i<=2*n;i++){
            int x; cin>>x;
            cnt += (x&1);
        }
        if(cnt==n)cout<<"Yes\n";
        else cout<<"No\n";

    }
    return 0;
}