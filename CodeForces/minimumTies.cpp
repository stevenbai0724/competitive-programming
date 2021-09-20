//https://codeforces.com/problemset/problem/1487/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        
        if(n&1){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(j-i<= n/2)cout<<1<<" ";
                    else cout<<-1<<" ";
                }
            }
            cout<<"\n";
        }
        else{
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(j-i <n/2)cout<<1<<" ";
                    else if(j-i == n/2 )cout<<0<<" ";
                    else cout<<-1<<" ";
                }

            }
            cout<<"\n";
        }
       
    }


    return 0;
}