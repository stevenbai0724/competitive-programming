//https://codeforces.com/contest/1476/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int n, k;
        cin>>n>>k;

        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        int l = -1;
        int r = 1e14;

        while(l+1 < r){
            int m = (l+r)/2;
            bool good = true;

            int sum = arr[1] + m;
            for(int i=2;i<=n;i++){
                if(100 * arr[i] > k * sum){
                    good = false;
                    break;
                }
                sum += arr[i];
            }
            if(good)r = m;
            else l = m; 

        }
        cout<<r<<"\n";



        
    }

    return 0;
 
}