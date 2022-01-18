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
    else if(n == 2){
        cout<<-1<<"\n";
    }
    else if(n == 3){
        cout<<"1 3 2\n";
    }
    else{
        int base = (n+1)/2;

        if(base&1){
            int last = n;
            if(n%2==0)last--;

            for(int i=1;i<=n;i+=2){
                if(i!=last)cout<<i<<" ";
            }
            for(int i=2;i<=n;i+=2){
                cout<<i<<" ";
            }
            cout<<last<<"\n";

        }
        else{
            for(int i=1;i<=n;i+=2){
                cout<<i<<" ";
            }
            for(int i=2;i<=n;i+=2){
                cout<<i;
                if(i+2 <=n)cout<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
