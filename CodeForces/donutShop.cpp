//
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
        int a, b, c;
        cin>>a>>b>>c;

        if(a>=c){
            cout<<-1<<" ";
        }
        else{
            cout<<1<<" ";
        }

        if(a*b >c){
            cout<<b<<"\n";
        }
        else cout<<-1<<"\n";

    }
    

    return 0;
}