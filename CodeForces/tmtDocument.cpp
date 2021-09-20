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
        string s; cin>>s;
        vector<int>mInd;
        vector<int>tInd;
        bool good = true;

        for(int i=0;i<s.length();i++){
            if(s[i]=='T')tInd.push_back(i);
            else mInd.push_back(i);
        }
        if(mInd.size() * 2 != tInd.size()){
            cout<<"NO\n";
            continue;
        }

        for(int i=0;i<mInd.size();i++){
            int st = tInd[i];
            int nd = tInd[i+mInd.size()];
            if(st>mInd[i] || nd<mInd[i])good =false;
        }
        
        if(good )cout<<"YES\n";
        else cout<<"NO\n";




    }


    return 0;
}