//https://codeforces.com/problemset/problem/1459/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    
    if(n&1)cout<<(n/2 + 2) * (n/2 + 1) * 2<<"\n";
    else cout<<(n/2 + 1) * (n/2 + 1)<<"\n";


    return 0;
}