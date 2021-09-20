//https://codeforces.com/problemset/problem/758/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int mx = 0;
    vector<int>arr(n+1);
    int ans = 0;

    for(int i =1;i<=n;i++){
        cin>>arr[i];
        mx = max(arr[i], mx);
    }
    for(int i=1;i<=n;i++){
        ans += mx - arr[i];
    }
    cout<<ans;
    



    return 0;
}
