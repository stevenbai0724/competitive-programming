//https://codeforces.com/problemset/problem/1512/D
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
        int n; cin>>n;

        vector<int>arr(n+2);
        int bigSum = 0;
        for(int i=0;i<n+2;i++){
            cin>>arr[i];
            bigSum +=arr[i];
        }
        sort(arr.begin(), arr.end());

        int mx = arr[n+1];
        int mx2 = arr[n];

        int case1 = bigSum-mx;
        int case2 = bigSum-mx2;

        for(int i=0;i<n+1;i++){
            int temp = case1 - arr[i];
            if(temp==mx){
                for(int j=0;j<n+1;j++){
                    if(j==i)continue;
                    cout<<arr[j]<<" ";
                }
                cout<<"\n";
                goto nxt;
            }
        }


        for(int i=0;i<n+2;i++){
            if(i==n)continue;
            int temp = case2 - arr[i];
            if(temp==mx2){
                for(int j=0;j<n+2;j++){
                    if(j==i || j==n)continue;
                    cout<<arr[j]<<" ";
                }
                cout<<"\n";
                goto nxt;

            }
        }
        cout<<-1<<"\n";


        nxt:;


        

    }

    return 0;
}