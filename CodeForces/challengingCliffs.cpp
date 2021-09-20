//https://codeforces.com/problemset/problem/1537/C
#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1);

        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }


        sort(arr.begin(), arr.end());
        if(n==2){
            cout<<arr[1]<<" "<<arr[2]<<"\n";
            continue;
        }
        int l, r;

        int mn = 1e18;

        for(int i=1;i<n;i++){
            int diff = abs(arr[i]-arr[i+1]);
            if(diff<mn){
                mn = diff;
                l = i;
                r = i+1;
            }
        }
        vector<int>ans;

        for(int i=r;i<=n;i++){
            ans.push_back(arr[i]);
        }
        for(int i=1;i<=l;i++){
            ans.push_back(arr[i]);
        }

        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<"\n";



    }


    return 0;
}