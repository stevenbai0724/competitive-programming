//https://codeforces.com/problemset/problem/1598/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);
        gp_hash_table<int, int>freq;
        double sum = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            freq[arr[i]]++;
            sum += arr[i];
        }
        double mean = sum/n;

        if(mean*2.0 != (int)(mean*2.0)){
            cout<<0<<"\n";
            continue;
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            int comp = (mean*2) - arr[i];
            if(arr[i]==mean){
                ans += freq[arr[i]] - 1;
            }
            else ans += freq[comp];
        }
    
        cout<<ans/2<<"\n";

    }




    return 0;
}