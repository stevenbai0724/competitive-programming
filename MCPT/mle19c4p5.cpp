#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define double long double
#define ULL unsigned long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<pair<int, int>>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    unsigned long long mn = 1e19;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            mn = min(mn, (ULL)abs(arr[i].first - arr[j].first) + (ULL)abs(arr[i].second - arr[j].second));
        }
    }
    cout<<mn<<"\n";

    return 0;
}