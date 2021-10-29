//https://codeforces.com/contest/1582/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr(62);
    arr[0] = 1;
    for(int i=1;i<=60;i++){
        arr[i] = arr[i-1]*2;
    }
    vector<int>val(62);

    val[1] = 1;
    for(int i=2;i<=60;i++){
        val[i] = val[i-1] + arr[i-1];
    }


    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int zero = 0;
        int one = 0;
        int sum = 0;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(x==0)zero++;
            if(x==1)one++;
        }

        cout<<val[zero]*one + one<<"\n";

    }

    return 0;
}