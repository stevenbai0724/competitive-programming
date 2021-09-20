#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int n; cin>>n;
    vector<int>arr(n+1);
    int ans;

    for(int i =1;i<n;i++){
        int x; cin>>x;
        arr[x]++;

    }
    for(int i =1;i<=n;i++){
        if(arr[i]==0){  
            ans = i;
            break;
        }
    }
    cout<<ans;
    return 0;
}