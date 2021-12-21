//https://dmoj.ca/problem/dmopc21c4p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
struct edge{
    long double x1, y1, x2, y2, x3, y3;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<edge>arr;
    for(int i=1;i<=n;i++){
        long double x1, y1, x2, y2, x3, y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        arr.push_back({x1,y1,x2,y2,x3,y3});
    }

    while(q--){
        long double x, y;
        cin>>x>>y;
        int cnt = 0;
        for(auto e: arr){
            long double area = (abs( ( e.x1 * (e.y2-e.y3)) + (e.x2 * (e.y3 - e.y1)) + (e.x3 * (e.y1-e.y2)) ))/2.0;
            long double A = (abs( ( x * (e.y2-e.y3)) + (e.x2 * (e.y3 - y)) + (e.x3 * (y-e.y2)) ))/2.0;
            long double B = (abs( ( e.x1 * (y-e.y3)) + (x * (e.y3 - e.y1)) + (e.x3 * (e.y1-y)) ))/2.0;
            long double C = (abs( ( e.x1 * (e.y2-y)) + (e.x2 * (y - e.y1)) + (x * (e.y1-e.y2)) ))/2.0;

            int L = min(e.x1, min(e.x2, e.x3));
            int R = max(e.x1, max(e.x2, e.x3));
            int U = max(e.y1, max(e.y2, e.y3));
            int D = min(e.y1, min(e.y2, e.y3));
            if(L <= x && x <= R && D <= y && y <= U){
                if(A+B+C == area){
                    cnt++;
                    assert(L <= x && x <= R && D <= y && y <= U);
                }
            }

            
        }
        cout<<setprecision(200)<<cnt<<"\n";
    }

    return 0;
}