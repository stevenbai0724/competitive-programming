//https://dmoj.ca/problem/dmopc19c3p3
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

    int n; cin>>n;

    BIT bit;
    bit.init(5e5);

    int mod = 2e5;
    int sum = 0;
    int ans = 0;

    bit.update(0+mod, 1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==2)x = -1;
        sum += x;
        bit.update(sum+mod, 1);
        ans += bit.query(1, mod+sum-1);
    }
    cout<<ans<<"\n";



    

    return 0;
}