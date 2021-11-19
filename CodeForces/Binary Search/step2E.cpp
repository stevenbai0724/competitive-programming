//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    double c; cin>>c;

    double L = 0;
    double R = 1e8;

    int t = 100;
    while(t--){
        double m = (L+R)/2.0;

        if(m*m + (sqrt(m) ) < c) L = m;
        else R = m;
    }
    cout << fixed << setprecision(7) << R << "\n";

    return 0;
}