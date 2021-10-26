//https://cses.fi/problemset/task/1660
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin>>n>>x;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum = arr[1];
    int j = 1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(j<i){
            j = i;
            sum += arr[i];
        }

        while(j<n && arr[j+1]+sum<=x){
            sum += arr[j+1];
            j++;
        }   
        if(sum == x){
            ans++;
        }
        sum -= arr[i];

    }
    cout<<ans<<"\n";



    return 0;
}