//https://dmoj.ca/problem/ucrpc21c
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

    int k, n;
    cin>>k>>n;
    int A = k;
    int B = k;

    for(int i=1;i<=n;i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        A -= (a*b);
        B -= (c*d);

        if(A <=0 && B <= 0){
            cout<<"It's a tie at round "<<i<<"!\n";
            return 0;
        }
        else if(A <=0){
            cout<<"Team 1 wins at round "<<i<<"!\n";
            return 0;
        }
        else if(B <=0){
            cout<<"Team 2 wins at round "<<i<<"!\n";
            return 0;
        }

    }

    cout<<"Oh no!\n";

    return 0;
}
