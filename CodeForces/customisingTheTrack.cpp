//https://codeforces.com/problemset/problem/1543/B
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int sum = 0;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            sum+=x;

        }
        cout<<(sum%n)*(n - (sum%n))<<"\n";  


    } 


    return 0;   
}