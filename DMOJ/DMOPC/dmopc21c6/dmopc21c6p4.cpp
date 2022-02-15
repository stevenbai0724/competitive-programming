//
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
int mxn = 2e5+1;
vector<vector<int>>adj(mxn+1);
vector<vector<int>>parent(3, vector<int>(mxn));
void dfs(int u, int p, int i){
    for(int nxt: adj[u]){
        if(nxt == p)continue;
        parent[i][nxt] = u;
        dfs(nxt, u, i);
    }
    return;
}   
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>>edges(m+1);

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        if(x > y)swap(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges[i] = {x,y};
    }

    int a, b, c, d;
    cin>>a>>b>>c>>d;

    for(int i=1;i<=m;i++){
        if(edges[i] == pair<int, int>{c,d} || edges[i] == pair<int, int>{d,c}){
            cout<<-1<<"\n";
            return 0;
        }
    }

    dfs(a, 0, 1);

    int cur = b;

    set<pair<int, int>>path;

    while(parent[1][cur] != 0){
        int x = cur;
        int y = parent[1][cur];

        if(x > y)swap(x, y);

        path.insert({x,y});

        cur = parent[1][cur];


    }

    

    dfs(c, 0, 2);

    cur = d;
    int ansX = 1e18;
    int ansY = 1e18;

    while(parent[2][cur] != 0){
        int x = cur;
        int y = parent[2][cur];

        if(x > y)swap(x, y);

        if(path.find({x, y}) == path.end()){
            ansX = x;
            ansY = y;
        }
        cur = parent[2][cur];
    }

    if(ansX == 1e18)cout<<-1<<"\n";
    else{
        cout<<2<<"\n";
        for(int i=1;i<=m;i++){
            int x = edges[i].first;
            int y = edges[i].second;
            if(x == ansX && y == ansY)cout<<2<<"\n";
            else cout<<1<<"\n";
        }
    }











    return 0;
}
/*
9 8
1 2
2 3
1 4
4 5
4 6
1 7
7 8
7 9
5 1 6 7

*/