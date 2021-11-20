//https://dmoj.ca/problem/ccc05j2
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

    int cnt = 0;
    int a, b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        int f = 0;
        for(int j=1;j<=i;j++){
            if(i%j == 0)f++;
        }
        if(f==4)cnt++;
    }
    cout<<"The number of RSA numbers between "<<a<<" and "<<b<<" is "<<cnt<<"\n";

    return 0;
}