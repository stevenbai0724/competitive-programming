//https://dmoj.ca/problem/dmopc14c2p6
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
        size = n;
        arr.resize(n+5);
    }
    void update(int x, int val){
        for(int a = x; a<=size; a+=a&-a){
            arr[a] += val;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>=1; a-=a&-a){
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
struct Query{
    int id, x, y, w;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    BIT bit;
    bit.init(n);

    priority_queue<pair<int, int>>q;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        q.push({x,i});
    }
    vector<Query>arr;
    

    int k; cin>>k;
    vector<int>ans(k+1);

    for(int i=1;i<=k;i++){
        int x, y, w;
        cin>>x>>y>>w;
        x++;
        y++;

        arr.push_back({i,x,y,w});

    }

    sort(arr.begin(), arr.end(), [](Query a, Query b){
        return a.w > b.w;
    });

    for(Query nxt: arr){
        int id = nxt.id;
        int x = nxt.x;
        int y = nxt.y;
        int w = nxt.w;

        while(!q.empty() && q.top().first >=w){
            int ind = q.top().second;
            bit.update(ind, q.top().first);
            q.pop();
        }

        ans[id] = bit.query(x, y);

    }
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<"\n";
    }





    return 0;
}
