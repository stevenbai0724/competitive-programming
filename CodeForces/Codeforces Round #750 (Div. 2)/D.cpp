//https://codeforces.com/contest/1582/problem/D
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

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        if(n%2==0){
            for(int i=1;i<=n;i++){
                if(i&1){
                    cout<<arr[i+1]<<" ";
                }
                else{
                    
                    cout<<arr[i-1]*-1<<" ";
                
                }
            }
        }
        else {
            for(int i=1;i<=n-3;i++){
            
                if(i&1){
                    cout<<arr[i+1]<<" ";
                }
                else{
                    
                    cout<<arr[i-1]*-1<<" ";
                
                }
            
            }
            int a = arr[n-2];
            int b = arr[n-1];
            int c = arr[n];

            if(a+b!=0){
                cout<<-c<<" "<<-c<<" "<<(a+b);
            }
            else if(a+c!=0){
                cout<<-b<<" "<<(a+c)<<" "<<-b;
            }
            else {
                cout<<(b+c)<<" "<<-a<<" "<<-a;
            }

       }
       cout<<"\n";
    }



    return 0;
}