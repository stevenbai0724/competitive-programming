//https://dmoj.ca/problem/dmopc15c4p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, q;
    cin>>n>>k>>q;

    vector<int>arr(n+1);
    vector<int>psa(n+1);

    vector<vector<int>>ind(6000);
    int mod = 1200;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i] = psa[i-1];
        psa[i] += arr[i];
        assert(arr[i]<=1000 && arr[i] >= -1000);
        if(arr[i]<=1000 && arr[i] >= -1000)ind[arr[i]+mod].push_back(i);

    }
    for(int i=1;i<=5999;i++){
        ind[i].push_back(1e9);
    }

    while(q--){
        int a, b, x, y;
        cin>>a>>b>>x>>y;
        if(psa[y] - psa[x-1] > k ){
            auto it = lower_bound(ind[a+mod].begin(), ind[a+mod].end(), x);
            auto it2 = lower_bound(ind[b+mod].begin(), ind[b+mod].end(), x);
            if(*it<=y && *it2<=y)cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }



    return 0;
}