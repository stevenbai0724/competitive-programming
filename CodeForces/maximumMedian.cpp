//https://codeforces.com/contest/1201/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int ind = n/2 + 1;
    int L = arr[ind];
    int R = 2000000001;

    while(L+1 < R){
        int m = (L+R)/2;
        int cost = 0;
        for(int i=ind;i<=n;i++){
            cost += max((int)0, m-arr[i]);
        }
        if(cost<=k)L = m;
        else R = m;
    }
    cout<<L<<"\n";

    
    

    return 0;
}