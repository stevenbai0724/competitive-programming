//https://codeforces.com/problemset/problem/104/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    if(n==10 || n>21 || n<10)cout<<0;
    else if (n==20)cout<<15;
    else cout<<4;

    return 0;
}
