//https://codeforces.com/problemset/problem/1345/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(int a, int b){
    return a>b;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    vector<int>arr{2};
    int inc = 5;
    for(int i=1;i<=1e6;i++){
        arr.push_back(arr[i-1] + inc);
        inc += 3;
    }

    while(t--){
        
        int n; cin>>n;
        int ans = 0;

        while(n>1){
            auto it = upper_bound(arr.begin(), arr.end(), n);
            it--;
            int val = *it;
            n -= val;
            ans++;
        }
        cout<<ans<<"\n";

        
    }

    return 0;
}