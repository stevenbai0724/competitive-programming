//https://dmoj.ca/problem/mwc15c7p2
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
        arr.resize(n+5);
        size = n;
    }
    void update(int x, int val){
        for(int a = x; a<=size; a+=a&-a){
            arr[a] += val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a >= 1; a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    void change(int x, int val){
        int v = query(x) - query(x-1);
        update(x, val-v);
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int k; cin>>k;
    vector<BIT>arr(k+1);
    int n; cin>>n;
    for(int i=1;i<=k;i++){
        arr[i].init(n);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            arr[i].update(j, x);
        }
    }
    int q; cin>>q;
    while(q--){
        int x, y, c;
        cin>>x>>y>>c;
        cout<<arr[c].query(x, y)<<"\n";
    }


    return 0;
}