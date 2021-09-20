//https://codeforces.com/contest/1475/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    

    vector<int>arr;
    int p = 1;
    for(int i=1;i<=50;i++){
        p*=2;
        arr.push_back(p);
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n%2==1)cout<<"YES\n";
        else if(find(arr.begin(), arr.end(), n) == arr.end())cout<<"YES\n";
        else cout<<"NO\n";
    }
   
    return 0;

}