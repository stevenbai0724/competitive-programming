//https://codeforces.com/problemset/problem/1353/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int>arr(5e5+4);

    arr[1] = 0;

    for(int i=3;i<=5e5;i+=2){
        arr[i] = arr[i-2] + (i/2)*8*(i/2);
    }

    
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<arr[n]<<"\n";
    }

    


    return 0;
}