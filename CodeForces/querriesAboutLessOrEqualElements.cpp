//https://codeforces.com/problemset/problem/600/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<int>arr(n+1);
    vector<pair<int, int>>qer(m+1);
    vector<int>ans(m+1);
    qer[0] = {-1e18, -1e18};
    arr[0] = -1e18;


    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=m;i++){
        int x; cin>>x;
        qer[i] = {x,i};
    }
    sort(arr.begin(), arr.end());
    sort(qer.begin(), qer.end());

    int l = 0;

    for(int i=1;i<=m;i++){
        int ind = qer[i].second;
        int val = qer[i].first;
        
        while(l<n && arr[l+1]<=val)l++;

        ans[ind] = l;
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    return 0;
}