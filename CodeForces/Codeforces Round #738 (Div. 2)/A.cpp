//https://codeforces.com/contest/1559/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        
        int x = arr[1];
        for(int i=2;i<=n;i++){
            x = x&arr[i];
          
        }
        cout<<x<<"\n";
       
    }


    return 0;
}