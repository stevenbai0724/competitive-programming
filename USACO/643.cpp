//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
//USACO 2016 Open Contest Silver P2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int mx = 0;
    int j = 1;
    vector<pair<int, int>>edges(n+1);
    vector<int>sfx(n+2);
    for(int i=1;i<=n;i++){
        j = max(j, i);
        int cur = arr[i];
        while(j<n && arr[j+1]-cur<=k){
            j++;
        }
        edges[i] = {i,j};
        
    }
    sfx[n+1] = 0;
    for(int i=n;i>=1;i--){
        sfx[i] = max(sfx[i+1], edges[i].second-edges[i].first+1);
    }
    for(int i=1;i<=n;i++){
        mx = max(mx, edges[i].second - edges[i].first + 1 + sfx[edges[i].second+1]);
    }
    cout<<mx<<"\n";





    return 0;
}