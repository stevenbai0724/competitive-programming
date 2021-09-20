//https://codeforces.com/problemset/problem/1385/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
    
        int n; cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int ptr =n;
        while(ptr>1 && arr[ptr-1]>=arr[ptr])ptr--;
        while(ptr>1 && arr[ptr-1]<=arr[ptr])ptr--;
        cout<<ptr-1<<"\n";

    }

    return 0;
}