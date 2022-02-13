//https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int mxn = 2e5+2;
vector<int>euler{0};
vector<int>val(mxn+1);
vector<int>ind(mxn+1);
vector<int>ind2(mxn+1);
vector<vector<int>>adj(mxn+1);
vector<int>STS(mxn+1);
 
struct BIT{
    vector<int>arr;
    int size;
    void init(int n){
        arr.resize(n+5  );
        size = n;
    }
    void update(int x, int v){
        for(int a=x;a<=size;a+=a&-a){
            arr[a] +=v;
        }
    }
    int query(int x){
        int sum = 0;
        for(int a = x; a>=1; a-=a&-a){
            sum += arr[a];
        }
        return sum;
    }
    int query(int x, int y){
        return query(y) - query(x-1);
    }
    void change(int x, int val){
        int v = query(x) - query(x-1);
        update(x, val-v);
    }
};
void dfs(int u, int p){
    ind[u] = euler.size();
    euler.push_back(u);
    STS[u] = 1;
 
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        
        dfs(nxt, u);
        STS[u] += STS[nxt];
    }
 
    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int n, q;
    cin>>n>>q;
 
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
 
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    dfs(1, 0);
 
    BIT bit;
    bit.init(n);
 
    for(int i=1;i<=n;i++){
        int index = ind[i];
        bit.update(index, val[i]);
    }
 
    while(q--){
        int k;
        cin>>k;
        if(k == 1){
            int s, x;
            cin>>s>>x;
 
            bit.change(ind[s], x);
        }
        else{
            int x; cin>>x;
            int sz = STS[x];
            int R = ind[x]+sz-1;
            int L = ind[x];
            cout<<bit.query(L, R)<<"\n";
        }
    }
 
    return 0;
}