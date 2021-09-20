//https://codeforces.com/problemset/problem/1535/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;

        vector<int>arr(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        arr[0] = 1e18;

        vector<int>even;
        vector<int>odd;

        sort(arr.begin(), arr.end(), comp);

        for(int i=1;i<=n;i++){
            if(arr[i]&1)odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }

        vector<int>ans;
        for(auto x: even) ans.push_back(x);
        for(auto x: odd) ans.push_back(x);

        int cnt = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(__gcd(ans[i],ans[j]*2) != 1)cnt++;
            }
        }
        cout<<cnt<<"\n";




    }


    return 0;
}