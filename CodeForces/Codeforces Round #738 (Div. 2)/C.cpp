//https://codeforces.com/contest/1559/problem/C
#include <bits/stdc++.h>
using namespace std;
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

        if(arr[1]==1){
            cout<<n+1<<" ";
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<"\n";
            continue;
        }
        else if(arr[n]==0){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<n+1<<"\n";
            continue;
        }
        else {
            int go, back;
            for(int i=1;i<n;i++){
                if(arr[i]==0 && arr[i+1]==1){
                    go = i;
                    back = i+1;
                    break;
                }
            }
            for(int i=1;i<=go;i++){
                cout<<i<<" ";
            }
            cout<<n+1<<" ";
            for(int i=back;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<"\n";
            continue;
        }

    }


    return 0;
}