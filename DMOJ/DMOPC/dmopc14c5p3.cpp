//https://dmoj.ca/problem/dmopc14c5p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int mx = 1;
    int n; cin>>n;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        int j = i;

        while(j<n && abs(arr[j+1]-arr[j])<=2){
            j++;
        }
        mx = max(j-i+1, mx);
    }
    cout<<mx<<"\n";




    return 0;
}