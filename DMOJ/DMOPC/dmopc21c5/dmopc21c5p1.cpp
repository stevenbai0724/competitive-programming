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

    int n; cin>>n;

    if(n == 1){
        cout<<1<<"\n";
    }
    else if(n <= 4){
        cout<<-1<<"\n";
    }
    else if(n == 5){
        cout<<"1 3 5 4 2\n";
    }
    else{
        for(int i=1;i<=n;i++){
            if(i&1 && i!=5)cout<<i<<" ";
        }
        cout<<"5 4 ";
        for(int i=1;i<=n;i++){
            if(i%2 == 0 && i!=4){
                cout<<i;
                if(i+2<=n)cout<<" ";
            }
            
        }
        cout<<"\n";

    }

    return 0;
}
