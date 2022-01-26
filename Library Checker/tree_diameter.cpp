//https://judge.yosupo.jp/problem/tree_diameter
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
int mxn = 5e5 + 5;
vector<vector<pair<int, int>>>adj(mxn);
vector<int>dis1(mxn), dis2(mxn);
int mx = 0;
int START;
vector<int>parent(mxn);
void dfs(int u, int p, int i){
    for(auto pii: adj[u]){
        int w = pii.first;
        int y = pii.second;
        if(y == p)continue;
        
        if(i == 1){
            dis1[y] = dis1[u] + w;
            if(dis1[y] > mx){
                mx = dis1[y];
                START = y;
            }
            dfs(y, u, 1);
        }
        else{
            dis2[y] = dis2[u] + w;
            parent[y] = u;
            if(dis2[y] > mx){
                mx = dis2[y];
                START = y;
            }
            dfs(y, u, 2);
        }

    }
}   

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        x++;
        y++;

        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    dfs(1, 0, 1);

    mx = 0;
    dfs(START, 0, 2);
    vector<int>ans;

    int cur = START;

    while(cur != 0){
        ans.push_back(cur);
        cur = parent[cur];
    }

    cout<<mx<<" "<<ans.size()<<"\n";

    for(int x: ans){
        cout<<x-1<<" ";
    }
    cout<<"\n";





    return 0;
}
