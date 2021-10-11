//https://codeforces.com/contest/1579/problem/E1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int mod = n+4;
        vector<int>ans((2*n)+10);
        int FIRST; cin>>FIRST;
        int L = mod;
        int R = mod;
        ans[mod] = FIRST;
        for(int i=1;i<n;i++){
            int x; cin>>x;
            if(x<ans[L]){
                L--;
                ans[L] = x;
            }
            else{
                R++;
                ans[R] = x;
            }
        }
        for(auto x: ans){
            if(x!=0)cout<<x<<" ";
        }
        cout<<"\n";


    }


    return 0;
}