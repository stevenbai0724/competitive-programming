//https://codeforces.com/problemset/problem/1547/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int>x(n+1);
        vector<int>y(n+1);
        vector<int>ans(n+1);

        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        y[1] = 0;
        ans[1] = y[1] ^ x[1];

        for(int i=2;i<=n;i++){
            y[i] = (ans[i-1]|x[i])^x[i];
            ans[i] = y[i] ^ x[i];
        }
        for(int i=1;i<=n;i++){
            cout<<y[i]<<" ";
        }
        cout<<"\n";



    }


    return 0;
}