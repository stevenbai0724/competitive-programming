//https://codeforces.com/problemset/problem/764/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, z;
    cin>>n>>m>>z;
    int ans = 0;
    for(int i =min(n,m);i<=z;i++){
        if(i%n ==0 && i%m ==0) ans ++;
    }
    cout<<ans;

    return 0;
}
