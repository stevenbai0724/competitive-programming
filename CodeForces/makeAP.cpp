//https://codeforces.com/problemset/problem/1624/B
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
        int a, b, c;
        cin>>a>>b>>c;

        //ab, bc, ac    
        bool good = false;

        if(true){
            int target = b + b - a;
            if(target>=c && target%c == 0 && target != 0)good = true;

        }
        if(true){
            int target = b - (c - b);
            if(target>=a && target%a==0 && target !=0)good = true;
            
        }
        if(true){
            int target = a + ((c-a)/2);

            if(target>=b && target%b==0 && target!=0 && (c-a)%2 == 0)good = true;

            
        }
        cout<<(good ? "YES\n" : "NO\n");
    }

    return 0;
}
