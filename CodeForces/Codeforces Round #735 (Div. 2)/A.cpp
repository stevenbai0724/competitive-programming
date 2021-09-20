//https://codeforces.com/contest/1554/problem/A
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
        int mx = 0;
        for(int i=1;i<n;i++){
            mx = max(arr[i]*arr[i+1], mx);
        }
        cout<<mx<<"\n";
    }


    return 0;
}