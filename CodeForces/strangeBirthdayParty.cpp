//https://codeforces.com/problemset/problem/1366/A
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
        int n, m;
        cin>>n>>m;

        vector<int>arr(n+1);
        vector<int>buy(m+1);
        arr[0] = 1e18;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=m;i++){
            cin>>buy[i];
            
        }
        sort(arr.begin(), arr.end(), comp);

        int cur = 1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            int k = arr[i];
            if(buy[k]<=buy[cur] && cur<=m){
                ans += buy[k];
            }
            else{
                ans += buy[cur];
                cur++;
            }
        }
        cout<<ans<<"\n";



    }

    return 0;
}