//https://codeforces.com/problemset/problem/1401/C
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
        int mn = 1e18;

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mn = min(mn, arr[i]);
        }
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());

        bool ans = true;
        for(int i=1;i<=n;i++){
            if(arr[i]%mn!=0){
                if(arr[i]!=sorted[i])ans = false;
            }
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
        
    }


    return 0;
}