#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+2);
    arr[0] = -(int)1e18;
    arr[n+1] = (int)1e18;

    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=k;i++){
        int x;cin>>x;

        int l=0,r = n+1;

        while(l+1<r){
            int m = (l+r)/2;

            if(arr[m]<x) l = m;
            else r = m;
        }
        cout<<r<<"\n";
    }
    return 0;
}