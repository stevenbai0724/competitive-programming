//https://codeforces.com/problemset/problem/1420/C1
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int>arr(n+1);
        vector<int>dpOdd(n+2);
        vector<int>dpEven(n+2);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        
        dpOdd[0] = -1e18;
        
        

        for(int i=0;i<=n;i++){  
            dpOdd[i+1] = max(dpOdd[i], dpEven[i]+arr[i]);
            dpEven[i+1] = max(dpEven[i], dpOdd[i] - arr[i]);
        }
        cout<<max(dpOdd[n+1], dpEven[n+1])<<"\n";

    }


    return 0;
}