//https://dmoj.ca/problem/dwite07c5p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 5;
    while(t--){
        int n; cin>>n;

        int ans = 0;
        int big = n;
        
        for(int i=2;i<=big;i++){
            while(n%i==0){
                n/=i;   
                ans++;
            }
            
        }
        if(ans==1){
            cout<<0<<"\n";
            continue;
        }
        cout<<ans<<"\n";

    }



    return 0;
}