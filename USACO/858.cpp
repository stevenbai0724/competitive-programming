//http://www.usaco.org/index.php?page=viewproblem2&cpid=858
//USACO 2018 December Contest Silver P1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin>>n>>m>>c;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int R = 1e18;
    int L = -1;

    while(L+1<R){
        int mid = (L+R)/2;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int j = i;
            int len = 1;
            int cur = arr[i];
            while(j<n && len<c && arr[j+1]-cur <= mid){
                j++;
                len++;
            }
            cnt++;
            i = j;

        }
        if(cnt<=m)R = mid;
        else L = mid;
    }
    cout<<R<<"\n";

    return 0;
}