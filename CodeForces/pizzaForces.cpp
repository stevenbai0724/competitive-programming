//https://codeforces.com/problemset/problem/1555/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        if(n&1)n++;

        n = max(n, (int)6);

        cout<<n/2*5<<"\n";
        
    }


    return 0;
}