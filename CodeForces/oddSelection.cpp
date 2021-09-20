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
        int n, x;
        cin>>n>>x;
        int even = 0, odd = 0;

        for(int i=1;i<=n;i++){
            int num; cin>>num;
            even+= (!(num&1));
            odd += (num&1);
        }

        for(int i=1;i<=(min(odd, x));i+=2){
            if(even>=(x-i)){
                cout<<"yes\n";
                goto nxt;
            }
        }
        cout<<"no\n";
        nxt:;
        

    }

  

    return 0;
}