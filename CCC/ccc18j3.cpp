//https://dmoj.ca/problem/ccc18j3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>psa(6);

    for(int i=1;i<=4;i++){
        int x; cin>>x;
        psa[i] = psa[i-1];
        psa[i] += x;
    }
    psa[5] = psa[4];

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            int a = max(i, j);
            int b = min(i, j);
            cout<<psa[a-1]-psa[b-1]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}