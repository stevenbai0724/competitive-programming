//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
//USACO 2017 Open Contest Silver P1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n; cin>>n;
    vector<pair<int, int>>arr(n+1);

    for(int i=1;i<=n;i++){
        int x, y ;
        cin>>x>>y;
        arr[i] = {y,x};
    }
    sort(arr.begin(), arr.end());

    int L = 1;
    int R = n;
    int mx = 0;
    while(L<R){
        mx = max(mx, arr[R].first + arr[L].first);
        int temp = min(arr[L].second, arr[R].second);
        arr[L].second -= temp;
        arr[R].second -= temp;
        if(arr[L].second == 0 )L++;
        if(arr[R].second == 0 )R--;

    }
    if(L==R)mx = max(mx, (int)arr[L].first*2);
    cout<<mx<<"\n";

    return 0;
}