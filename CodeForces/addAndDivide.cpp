//https://codeforces.com/problemset/problem/1485/A
//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;


int solve(int a, int b){
    int ans = 1e18;
    
    
    for(int i = b;i<=(max(b, (int)6));i++){
        int temp = a;
        int op = 0;
        while(temp>0 && op<=30){
            temp/=i;
            op++;
        }
        ans = min(ans, op+(i-b));
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;

        cout<<solve(a,b)<<"\n";

    }

    return 0;
}