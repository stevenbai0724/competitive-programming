//https://dmoj.ca/problem/grind
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
    vector<int>arr;
    int size;
    void init(int n){
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){ //add val to index x;
        for(int a=x ; a<=size; a+=a&-a){
            arr[a]+=val;
        }
    }
    int query(int x){ //get the value of x
        int sum = 0;
        for(int a=x;a>0;a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x) - query(x-1);
        update(x, val-v);

        
    }
    int query(int x, int y){
        return (query(y) - query(x-1));
    }

};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    BIT bit;
    bit.init(1e7);
    while(n--){
        int x, y;
        cin>>x>>y;
        bit.update(x, 1);
        bit.update(y, -1);
    }
    int ans = 0;
    for(int i=1;i<=1e7;i++){
        ans = max(ans, bit.query(i));

    }
    cout<<ans<<"\n";

    return 0;
}
