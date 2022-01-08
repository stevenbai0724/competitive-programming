//https://dmoj.ca/problem/bsspc21s2
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
struct edge{
    int a, b, c, d;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, q;
    cin>>n>>k>>q;

    vector<edge>arr;

    for(int i=1;i<=k;i++){
        int a, b, c,d;
        cin>>a>>b>>c>>d;
        arr.push_back({a,b,c,d});
    }
    reverse(arr.begin(), arr.end());

    while(q--){
        int curx, cury;
        cin>>curx>>cury;

        for(auto e: arr){
            int a = e.a;
            int b = e.b;
            int c = e.c;
            int d = e.d;

            if(a <= curx && curx <= c && b<= cury && cury<=d){
                int cols = cury - b;
                int rows = curx - a;
                int newx = c - cols;
                int newy = b + rows;
                curx = newx;
                cury = newy;
            }
        }

        cout<<(curx-1)*n + cury<<"\n";
    }

    return 0;
}
