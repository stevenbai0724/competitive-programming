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

    int n, m;
    cin>>n>>m;
    if(n == 1){
        cout<<0<<"\n";
        return 0;
    }
    if(n == 2){
        cout<<1<<"\n"<<1<<"\n";
        return 0;
    }
    if(n == 3){
        cout<<2<<"\n";
        cout<<1<<"\n"<<1<<"\n";
        return 0;
    }
    if(n&1){
        int mid = n/2+1;
        int dis = abs(mid - m);
        int val = (n/2)*(n/2 + 1)/2;
        if(val&1){ // moves are odd
            if(dis&1){
                cout<<n/2<<"\n";
                for(int i=1;i<=n/2;i++){
                    cout<<1<<"\n";
                }
            }
            else{
                cout<<n/2+1<<"\n";
                for(int i=1;i<=n/2+1;i++){
                    cout<<1<<"\n";
                }
            }
            
        }
        else{ //moves are even
            if(dis % 2 == 0){
                cout<<n/2<<"\n";
                for(int i=1;i<=n/2;i++){
                    cout<<1<<"\n";
                }
            }
            else{
                cout<<n/2+1<<"\n";
                for(int i=1;i<=n/2+1;i++){
                    cout<<1<<"\n";
                }
            }
        }


    }
    else{
        cout<<n/2<<"\n";
        for(int i=1;i<=n/2;i++){
            cout<<1<<"\n";
        }
    }

    return 0;
}
