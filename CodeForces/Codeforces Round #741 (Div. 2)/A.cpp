//https://codeforces.com/contest/1562/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int l, r;
        cin>>l>>r;
        cout<<min(r-l, (r+1)/2 - 1)<<"\n";
    }


    return 0;
}