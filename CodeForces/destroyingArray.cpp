//https://codeforces.com/problemset/problem/722/C
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
struct DSU{
    vector<int>parent;
    vector<int>val;
    vector<int>sz;

    void init(int n, vector<int>temp){
        parent.resize(n+1);
        sz.resize(n+1);
        val = temp;
        for(int i=1;i<=n;i++){
            sz[i] = 1;
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y)return ;
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            val[y] += val[x];
            parent[x] = y;
        }
        else{
            sz[x] += sz[y];
            val[x] += val[y];
            parent[y] = x;
        }
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    vector<int>que(n);
    vector<bool>vis(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>que[i];
    }
    reverse(que.begin(), que.end());

    DSU ds;
    ds.init(n, arr);

    vector<int>ans{0};

    int mx = 0;
    for(int i=0;i<n-1;i++){
        int cur = que[i];
        vis[cur] = true;
        if(cur-1 >= 1){
            if(vis[cur-1])ds.Union(cur, cur-1);
        }
        if(cur+1 <= n){
            if(vis[cur+1])ds.Union(cur, cur+1);
        }
        mx = max(mx, ds.val[ds.find(cur)]);

        ans.push_back(mx);
    }
    for(int i=n-1;i>=0;i--)cout<<ans[i]<<"\n";

    return 0;
}
