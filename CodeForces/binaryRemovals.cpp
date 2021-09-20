//binary removals
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    
    while(t--){
        
        string s; cin>>s;
        
        int i = s.find("11");
        int j = s.rfind("00");
        
        cout<<((i!=-1 && j!=-1 && i<j)?"NO\n":"YES\n");


    }


    return 0;
}