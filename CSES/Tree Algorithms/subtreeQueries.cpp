//https://cses.fi/problemset/task/1137/
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
vector<int>TTA{0,1};
vector<int>STS;
vector<int>ind;
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        arr.resize(n+7);
        size = n;
    }
    void update(int x, int val){
        for(int a = x; a <= size; a+=a&-a){
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
void dfs(int v, vector<vector<int>>&adj, vector<int>&colour){
    colour[v] = 1;
    STS[v] = 1;
    for(int u: adj[v]){
        if(colour[u] == 0){
            TTA.push_back(u);
            dfs(u, adj, colour);
            STS[v] += STS[u];
        }
    }
    colour[v] = 2;
    return;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<int>vals(n+1);
    STS.resize(n+1);
    ind.resize(n+1);

    BIT bit;
    bit.init(n);

    for(int i=1;i<=n;i++)cin>>vals[i];

    vector<vector<int>>adj(n+1);
    vector<int>colour(n+1);

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, adj, colour);

    for(int i=1;i<=n;i++){
        ind[TTA[i]] = i;
    }

    for(int i=1;i<=n;i++){
        int addIndex = ind[i];

        bit.update(addIndex, vals[i]);
    }

    while(q--){
        int k; cin>>k;
        if(k == 1){
            int s, x;
            cin>>s>>x;
            int index = ind[s];
            bit.change(index, x);
        }
        else{
            int x; cin>>x;
            int R = ind[x] + (STS[x] - 1);
            int L = ind[x];

            cout<<bit.query(L, R)<<"\n";
        }
    }
    return 0;
}
