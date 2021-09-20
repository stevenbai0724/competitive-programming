//https://codeforces.com/problemset/problem/755/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    if(n==1)cout<<3;
    else if(n==2)cout<<4;
    else cout<<n-2;



    return 0;
}
