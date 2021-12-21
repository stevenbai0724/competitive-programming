//https://dmoj.ca/problem/sac22cc2p5
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
        arr.resize(n+5);
    }
    void update(int x, int val){ //add
        for(int a = x; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>0; a-=a&-a){
            sum+=arr[a];
        }
        return sum;
    }
    void change(int x, int val){ //change
        int v = query(x)-query(x-1);
        update(x,val-v);
    }
    int query(int x, int y){//inclusive
        return query(y)-query(x-1);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    BIT odd, even;
    odd.init(n);
    even.init(n);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(i&1)odd.update(i,x);
        else even.update(i,x);
    }

    while(q--){
        int op; cin>>op;
        if(op == 1){
            int x, y;
            cin>>x>>y;
            if(x&1)odd.change(x, y);
            else even.change(x, y);
        }
        else{
            int x, y;
            cin>>x>>y;
            if(x&1)cout<<odd.query(x,y);
            else cout<<even.query(x, y);
            cout<<"\n";
        }
    }
    

    return 0;
}