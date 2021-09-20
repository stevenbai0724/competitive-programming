//https://codeforces.com/problemset/problem/1366/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;

        int free = abs(a-b);
        a = min(a,b);
        b = min(a,b);

        c+=free;

        int ans = min(a,c);

        a-=ans;
        b-=ans;
        c-=ans;

        if(a>0){
            ans += (a+b)/3;
        }

        cout<<ans<<"\n";


    }

    return 0;
}