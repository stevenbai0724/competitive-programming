//https://codeforces.com/problemset/problem/1335/C
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
            int x; cin>>x;
            arr[x]++;
        }
        int mx = *max_element(arr.begin(), arr.end());
		int diff = n + 1 - count(arr.begin(), arr.end(), 0);
		cout << max(min(mx - 1, diff), min(mx, diff - 1)) << "\n";
    }

    return 0;
}