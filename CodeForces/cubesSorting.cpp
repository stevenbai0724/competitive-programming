//https://codeforces.com/problemset/problem/1420/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
   return(a>=b);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        
        int n; cin>>n;

        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                cout<<"YES\n";
                goto nxt;
            }
        }
        cout<<"NO\n";
        nxt:;


    }

    return 0;   
}