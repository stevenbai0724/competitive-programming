//https://dmoj.ca/problem/gfssoc2j1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    int t; cin>>t;
    while(t--){
        int m; cin>>m;
        if(abs(n-m)>100) cout<<"go away! 3:<\n";
        else cout<<"fite me! >:3\n";
    }



    return 0;
}