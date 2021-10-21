//https://dmoj.ca/problem/ccc17j1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, y;
    cin>>x>>y;
    cout<<((x>0 && y>0) ? "1\n" : (y>0 ? "2\n" : (x>0 ? "4\n" : "3\n")));

    return 0;
}