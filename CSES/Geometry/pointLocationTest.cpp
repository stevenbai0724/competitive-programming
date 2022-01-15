//https://cses.fi/problemset/task/2189
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
#include <complex>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
#define X real()
#define Y imag()
typedef int C;
typedef complex<C>P;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        P p1 = {x1,y1};
        P p2 = {x2,y2};
        P p3 = {x3,y3};

        P c1 = {p3 - p1};
        P c2 = {p3 - p2};

        int val = (conj(c1)*c2).Y;

        if(val > 0)cout<<"LEFT\n";
        else if(val < 0)cout<<"RIGHT\n";
        else cout<<"TOUCH\n";

    }

    return 0;
}
