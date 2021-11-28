//http://www.usaco.org/index.php?page=viewproblem2&cpid=918
//USACO 2019 February Contest Silver P1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n; cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int tot = 0;
    for(int i=2;i<=n;i++){
        tot += (arr[i]-arr[i-1]-1);
    }
    assert(tot == (arr[n]-arr[1]+1-n));
    int ans1 = 1e18;

    if(arr[n-1] - arr[1] +1 == n-1 && arr[n]-arr[n-1] > 2){
        ans1 = 2;
    }
    else if(arr[n]-arr[2] + 1 == n-1 && arr[2] - arr[1] > 2){
        ans1 = 2;
    }
    else{
        int j = 0;
        for(int i=1;i<=n;i++){
            if(j<i){
                j = i;
            }
            while(j<n && arr[j+1]-arr[i]+1<=n){
                j++;
            }
            ans1 = min(ans1, n-(j-i+1));
        }
        
    }
    cout<<ans1<<"\n";

    cout<<max( (arr[n-1]-arr[1]+1) - n + 1, (arr[n]-arr[2]+1) - n + 1)<<"\n";



    return 0;
}