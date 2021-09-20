//https://codeforces.com/problemset/problem/1334/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){

        vector<int>arr(4);
        for(int i=1;i<=3;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());

        if(arr[3] >= (arr[2]+arr[1])){
            cout<<arr[2]+arr[1]<<"\n";
        }
        else{
            int ans = 0 ;

            int diff = arr[3]-arr[2];

            arr[3]-=diff;
            arr[1]-=diff;

            ans+=diff;

            ans += (arr[3]-arr[1]);

            arr[3] = arr[1];
            arr[2] = arr[1];

            ans += (arr[1]/2)*3;

            ans += arr[1]&1;

            cout<<ans<<"\n";
        }
    }
    return 0;   
}