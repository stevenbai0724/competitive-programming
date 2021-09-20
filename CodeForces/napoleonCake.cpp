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
        vector<int>arr(n+2);
        vector<int>psa(n+1);
        int sum = 0;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(x!=0){
                int nd = max((int)1, i-x+1);
                arr[nd]++;
                arr[i+1]--;
            }
        }
        for(int i=1;i<=n;i++){
            sum+=arr[i];
            psa[i] = sum;
        }
        for(int i=1;i<=n;i++){
            cout<<!(psa[i]==0)<<" ";
        }
        cout<<"\n";



    }

    return 0;
}