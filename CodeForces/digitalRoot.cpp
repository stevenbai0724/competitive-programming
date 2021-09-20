//https://codeforces.com/problemset/problem/1107/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    while(n-- >0){
        int k, x;
        cin>>k>>x;
        cout<<9*(k-1) + x<<"\n";
    }

    return 0;
}