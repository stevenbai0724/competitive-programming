//https://dmoj.ca/problem/dmopc14c2p6
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
struct edge{
    int x, y, id;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    BIT b;
    b.init(100000);
    vector<vector<int>>trees(20001);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        trees[x].push_back(i);
    }

    int q; cin>>q;
    vector<int>ans(q+1);
    vector<vector<edge>>querry(2e4+2);

    for(int i=1;i<=q;i++){
        int l, r, w;
        cin>>l>>r>>w;
        querry[w].push_back({l+1,r+1,i});
    }

    for(int i=20000;i>=1;i--){
        for(auto x: trees[i]){
            b.update(x, i);
        }
        for(auto e: querry[i]){
            int id = e.id;
            int l = e.x;
            int r = e.y;

            ans[id] = b.query(l,r);

        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }



    

    return 0;
}