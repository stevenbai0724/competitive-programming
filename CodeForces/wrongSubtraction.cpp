//https://codeforces.com/problemset/problem/977/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    while(k--){
        if(n%10!=0)n--;
        else n/=10;
    }
    cout<<n<<"\n";

    return 0;
}