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
    
        int n, k;
        cin>>n>>k;

        
        if(k<=(ceil(n/2.0))){
            cout<<setprecision(20)<<2*k -1<<"\n";
        }
        else{
            cout<<setprecision(20)<<(k-ceil(n/2.0))*2<<"\n";
        }

    
    

    return 0;
}