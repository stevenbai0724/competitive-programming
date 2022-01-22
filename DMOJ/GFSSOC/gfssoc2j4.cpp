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
struct BIT{
    int size;
    vector<int>arr;
    void init(int n){
        arr.resize(n+5);
        size = n;
    }
    void update(int x, int val){
        for(int a=x;a<=size;a+=a&-a){
            arr[a] += val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a=x; a>=1; a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x)-query(x-1);
        update(x, val-v);
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
    
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    BIT bit;
    bit.init(n);
    int sum = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        bit.update(i, x);
        sum +=x;
    }

    while(q--){
        int x, y;
        cin>>x>>y;

        cout<<sum - bit.query(x, y)<<"\n";

    }



    return 0;
}
