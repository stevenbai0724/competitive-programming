//https://dmoj.ca/problem/ccc16j1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int cnt = 0;
    for(int i=1;i<=6;i++){
        char c; cin>>c;
        cnt += c=='W';
    }

    if(cnt>=5)cout<<1<<"\n";
    else if(cnt>=3)cout<<2<<"\n";
    else if(cnt>=1)cout<<3<<"\n";
    else cout<<-1<<"\n";



    return 0;
}