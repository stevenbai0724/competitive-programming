//https://codeforces.com/contest/1520/problem/A
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

        string s; cin>>s;
        vector<vector<int>>ind(26);
        for(int i=0;i<n;i++){
            ind[s[i]-65].push_back(i);
        }

        bool good  = true;
        
        for(int i=0;i<26;i++){
            if(ind[i].empty())continue;
            for(int j=0;j<ind[i].size()-1;j++){
                if(ind[i][j]-ind[i][j+1] != -1)good = false;
            }
        }
        if(good)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}