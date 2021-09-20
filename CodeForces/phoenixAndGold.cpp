//https://codeforces.com/contest/1515/problem/A
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
        int n, k;
        cin>>n>>k;

        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=arr[i];
            if(sum==k && i==n){
                cout<<"NO\n";
                goto nxt;
            }
            if(sum==k && i!=n){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sum+=arr[i];
                i++;
            }
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        nxt:;

    }
    
    return 0;
}