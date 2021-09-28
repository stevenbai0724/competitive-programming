//bitmask
//https://dmoj.ca/problem/coci08c2p3
//sample problem implementing bitmasks

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {

    int n; cin>>n;

    vector<pair<int, int>>arr(n+1);
    int mn = 1e18;
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        arr[i] = {x,y};
    }
    //non empty subset
    for(int i = 1; i<(1<<n) ;i++ ){
        int p = 1;
        int s = 0;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                p *= arr[j+1].first;
                s += arr[j+1].second;
            }
        }
        mn = min(mn, abs(p-s));
    }
    cout<<mn<<"\n";


    return 0;
}