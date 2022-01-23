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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    while(true){
        int n; cin>>n;

        if(n == 0)break;
        int mn = 1e18;
        int x, y;

        for(int i=1;i*i<=n;i++){
            if(i*(n/i) == n){
                mn = i+i+(n/i)+(n/i);
                x = i;
                y = n/i;
            }
        }
        cout<<"Minimum perimeter is "<<mn<<" with dimensions "<<x<<" x "<<y<<"\n";


    }

    return 0;
}
