//https://dmoj.ca/problem/dmopc19c7p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int carbon = a+b+c;

    if(d==4+ 2*(carbon))cout<<"C"<<carbon+1<<"H"<<d<<"\n";
    else cout<<"invalid\n";

    return 0;
}