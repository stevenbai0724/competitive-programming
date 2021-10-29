//https://codeforces.com/problemset/problem/1360/E
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
        int n;
        cin>>n;
        vector<vector<bool>>arr(n+1, vector<bool>(n+1));

        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=n;j++){
                arr[i][j] = s[j-1] == '1';
            }
        }   
        bool good = true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]){
                    if(i==n || j==n)continue;
                    if(arr[i][j+1] || arr[i+1][j])continue;
                    good = false;

                }
            }
        }
        cout<<(good ? "YES\n" : "NO\n");
    }


    return 0;
}