//https://cses.fi/problemset/task/1648
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+1);
    }
    void update(int x, int val){ //add val to ind x
        for(int a = x; a<=size; a+=a&-a){
            arr[a] +=val;
        }
    }
    int query(int x){ //sum [1,r]
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    void change(int x, int val){ //change index x to val
        int v = query(x)-query(x-1);
        update(x,val-v);
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    BIT b; b.init(n);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        b.change(i, x);
    }

    while(q--){
        int o; cin>>o;
        if(o==1){
            int x, y;
            cin>>x>>y;
            b.change(x, y);
        }
        else {
            int x, y;
            cin>>x>>y;
            cout<<b.query(x, y)<<"\n";
        }
    }


    return 0;
}