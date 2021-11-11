//https://dmoj.ca/problem/ds1
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

    BIT b, freq;
    int n, q;
    cin>>n>>q;
    b.init(n);
    freq.init((int)1e5);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        b.change(i, x);
        freq.update(x,1);
    }
    
    while(q--){
        char c; cin>>c;
        if(c=='C'){
            int x, v;
            cin>>x>>v;
            freq.update(b.query(x, x),-1);
            b.change(x,v);
            freq.update(v,1);
        }
        if(c=='Q'){
            int v; cin>>v;
            cout<<freq.query(1, v)<<"\n";
        }
        if(c=='S'){
            int l, r;
            cin>>l>>r;
            cout<<b.query(l,r)<<"\n";
        }
    }

    

    return 0;
}