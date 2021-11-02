//https://dmoj.ca/problem/sac22cc1p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double l, h, w, d;
    cin>>l>>h>>w>>d;

    cout<<setprecision(20)<<(l*w*h) - (d/2.0)*(d/2.0)*(3.14159)*h<<"\n";


    return 0;
}