//https://codeforces.com/problemset/problem/38/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=2;i<=n;i++){
        cin>>arr[i];
    }
    int a, b;
    cin>>a>>b;
    int ans= 0 ;
    for(int i = a+1;i<=b;i++){
        ans+=arr[i];
    }
    cout<<ans;


    return 0;
}