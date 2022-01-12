//https://codeforces.com/problemset/problem/1620/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int w, h;
        cin>>w>>h;
        int ans = 0;
        int R, L;
        int a; cin>>a;

        for(int i=1;i<=a;i++){
            int x; cin>>x;
            if(i == 1)L = x;
            if(i == a)R = x;
        }
        ans = max(ans, (R-L)*h);

        int b; cin>>b;
        for(int i=1;i<=b;i++){
            int x; cin>>x;
            if(i == 1)L = x;
            if(i == b)R = x;
        }
        ans = max(ans, (R-L)*h);

        int c; cin>>c;
        for(int i=1;i<=c;i++){
            int x; cin>>x;
            if(i == 1)L = x;
            if(i == c)R = x;
        }

        ans = max(ans, (R-L)*w);

        int d; cin>>d;
        for(int i=1;i<=d;i++){
            int x; cin>>x;
            if(i == 1)L = x;
            if(i == d)R = x;
        }
        ans = max(ans, (R-L)*w);

        cout<<ans<<"\n";


        
    }

    return 0;
}
