//https://dmoj.ca/problem/ccc18s4
//subtask 1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>ans(1001);

    ans[1] = 1;

    for(int i=2;i<=1000;i++){
        for(int j=2;j<=i;j++){
            int w = i/j;
            ans[i] += ans[w];
        }
    }
    int n; cin>>n;
    cout<<ans[n]<<"\n";


    return 0;
}