//https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    map<int, int>m;

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        m[a]++; m[b]--;
    }
    int sum = 0;
    int ans = 0;
    for(auto x: m){
        sum+= x.second;
        ans = max(ans, sum);
    }
    cout<<ans;


    return 0;
}