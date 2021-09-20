//https://codeforces.com/contest/1520/problem/C
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
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        if(n==2){
            cout<<-1<<"\n";
            continue;
        }
        if(n==3){
            cout<<"2 9 7\n";
            cout<<"4 6 3\n";
            cout<<"1 8 5\n";
            continue;
        }
        vector<vector<int>>arr(n+1, vector<int>(n+1));
        int cnt = 1;
        for(int i=1;i<=n;i++){
            int j;
            if(i&1)j= 1;
            else j=2;
            for(j;j<=n;j+=2){
                arr[i][j] = cnt;
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            int j;
            if(i&1)j=2;
            else j = 1;
            for(j;j<=n;j+=2){
                arr[i][j] = cnt;
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }

    }



    return 0;
}