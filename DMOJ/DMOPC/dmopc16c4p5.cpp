//https://dmoj.ca/problem/dmopc16c4p5
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string std::string


struct DSU{
    vector<int>parent, sz;
    void init(int n){
        parent.resize(n+1);
        sz.resize(n+1);

        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
        
    }
    int find(int x){
        if(parent[x] == x)return x;
        return find(parent[x]);
    }
    void Union(int x, int y ){
        x = find(x);
        y = find(y);
        if(x==y)return;
        if(sz[x] < sz[y]){
            sz[y] += sz[x];
            parent[x] = y;

        }
        else{
            sz[x] += sz[y];
            parent[y] = x;
        }
    }


};
struct edge{
    int w, x, y;
};
bool comp(edge a, edge b){
    return a.w > b.w;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    DSU ds;
   

    vector<edge>arr;
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;

        arr.push_back({w, x, y});

    }

    int L = 1;
    int R = 1e9+1;

    sort(arr.begin(), arr.end(), comp);
    vector<vector<pair<int, int>>>adj(n+1);
    int t = 70;
    int mainCnt;
    while(t--){
        int mid = (L+R)/2; //min edge weight allowed
        ds.init(n);
        vector<vector<pair<int, int>>>temp(n+1);
        int cnt = 0;
        
        for(edge e: arr){
            if(e.w >= mid && ds.find(e.x)!=ds.find(e.y)){
                ds.Union(e.x, e.y);
                cnt++;
                temp[e.x].push_back({e.w, e.y});
                temp[e.y].push_back({e.w, e.x});
            }
        }
        adj = temp;
        mainCnt = cnt;
        if(ds.sz[ds.find(1)] == n)L = mid;
        else R = mid;
    
    }
    vector<int>dis(n+1), vis(n+1);

    assert(mainCnt == n-1);
    queue<int>q;
    q.push(1);
    dis[1] = 1e18;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto p: adj[cur]){
            int to = p.second;
            int w = p.first;
            if(!vis[to]){
                vis[to] = true;
                dis[to] = min(dis[cur], w);
                q.push(to);
            }
        }
    }
    cout<<0<<"\n";
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<"\n";
    }
    
    

    return 0;
}