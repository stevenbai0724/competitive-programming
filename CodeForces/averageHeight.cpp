//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int>even;
        vector<int>odd;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(x&1)odd.push_back(x);
            else even.push_back(x);
        }
        for(auto x: odd)cout<<x<<" ";
        for(auto x: even)cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}