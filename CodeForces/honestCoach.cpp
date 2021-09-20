//https://codeforces.com/contest/1360/problem/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t; t>0;t--){
        int n; cin>>n;
        int ans = 1e9;
        vector<int>arr(n+1);

        for(int i =1;i<=n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        for(int i =1;i<n;i++){
            ans = min(ans, arr[i+1]-arr[i]);
        }
        cout<<ans<<"\n";

    }

    return 0;
}