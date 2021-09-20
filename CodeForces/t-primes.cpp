//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
//(trunc(x) == x)
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int>prime(1e6+1, true);
    prime[1] = false;

    for(int i=2;i*i<=1e6;i++){
        if(prime[i]){
            for(int j=2;j*i<=1e6;j++){
                prime[i*j]= false;
            }
        }
    }
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        double root = sqrt(x);

        if(!(trunc(root)==root) || x==1){
            cout<<"NO\n";
            continue;
        }
        x = (int)root;
        if(prime[x])cout<<"YES\n";
        else cout<<"NO\n";
        
      
    }


    return 0;
}