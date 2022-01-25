//
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
struct edge1{
    int y1, x1, x2;
};
struct edge2{
    int x1, y1, y2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int h, v;
    cin>>h>>v;

    if(h == 1 || v == 1){
        cout<<0<<"\n";
        return 0;
    }

    vector<edge1>arr1(h+1);
    vector<edge2>arr2(v+1);

    for(int i=1;i<=h;i++){
        cin>>arr1[i].y1>>arr1[i].x1>>arr1[i].x2;
    }
    for(int i=1;i<=v;i++){
        cin>>arr2[i].x1>>arr2[i].y1>>arr2[i].y2;
    }

    for(int i=1;i<h;i++){
        for(int j=i+1;j<=h;j++){
            for(int k=1;k<=v;k++){

            }
        }
    }


    return 0;
}
