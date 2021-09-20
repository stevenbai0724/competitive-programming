//https://codeforces.com/problemset/problem/110/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int count = 0;
    while(n!=0){
        if(n%10 ==7 || n%10==4)count++;
        n/=10;
        
    }
    if(count==4 || count==7)cout<<"YES";
    else cout<<"NO";

    return 0;
}
