//https://codeforces.com/problemset/problem/630/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int>arr(56);
    arr[1] = 2;
    for(int i=2;i<=55;i++){
        arr[i] = (arr[i-1]-arr[i-2])*2 + arr[i-1];
    }
    int n; cin>>n;
    cout<<arr[n];
    return 0;
}