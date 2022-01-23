//https://dmoj.ca/problem/ccc10j2
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

    vector<int>N, B;

    int a, b, c, d, s;
    cin>>a>>b>>c>>d>>s;

    for(int i=1;i<=a;i++)N.push_back(1);
    for(int i=1;i<=b;i++)N.push_back(-1);
    for(int i=1;i<=c;i++)B.push_back(1);
    for(int i=1;i<=d;i++)B.push_back(-1);

    int x = 0;
    int y = 0;

    for(int i=0;i<s;i++){
        x += N[i%(a+b)];
        y += B[i%(c+d)];
    }

    if(x == y)cout<<"Tied\n";
    if(x > y)cout<<"Nikky\n";
    if(x < y)cout<<"Byron\n";

    return 0;
}
