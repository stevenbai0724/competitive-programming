//https://codeforces.com/contest/782/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>pos(n+1), v(n+1);

    for(int i=1;i<=n;i++){
        cin>>pos[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    double L= 0;
    double R = 5e8+3;
    int t = 100;
    while(t--){
        double m = (L+R)/2.0;
        double mn = 1e18;
        double mx = -1e18;
        for(int i=1;i<=n;i++){
            double x = pos[i] + (m*v[i]);
            double y = pos[i] - (m*v[i]);
            mn = min(mn, x);
            mx = max(mx, y);
        }
        if(mn>=mx)R = m;
        else L = m;

    }
    cout<<fixed<<setprecision(8)<<R<<"\n";


    return 0;
}