//https://cses.fi/problemset/task/2183
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int res =1;

    for(int i=1;i<=n;i++){
        if(res<arr[i]){
            cout<<res<<"\n";
            return 0;
        }
        res += arr[i];
    }

    cout<<res<<"\n";




    return 0;
}