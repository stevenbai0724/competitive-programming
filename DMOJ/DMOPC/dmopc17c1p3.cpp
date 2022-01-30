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
struct edge{
    int y, cnt, w;
};
class Compare{
    public:
        bool operator() (edge a, edge b){
            if(a.w == b.w){
                return a.cnt > b.cnt;
            }
            return a.w > b.w;
        }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    vector<int>dis(n+1, 1e18), mnCount(n+1, 1e18), vis(n+1);
    mnCount[1] = 0;
    dis[1] = 0;
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    priority_queue<edge, vector<edge>, Compare>q;

    q.push({1,0,0});

    while(!q.empty()){
        int y = q.top().y;
        int w = q.top().w;
        int cnt = q.top().cnt;
        q.pop();
        if(vis[y])continue;
        vis[y] = true;
        for(auto p: adj[y]){
            int neww = p.first;
            int newy = p.second;
            if(dis[newy] > dis[y] + neww){
                dis[newy] = dis[y] + neww;   
                mnCount[newy] = mnCount[y] + 1;
                q.push({newy, mnCount[newy], dis[newy]});
            }
            else if(dis[newy] == dis[y] + neww && mnCount[newy] > 1 + mnCount[y]){
                mnCount[newy] = 1 + mnCount[y];
                q.push({newy, mnCount[newy], dis[newy]});
            }
        }
    }
    if(dis[n] == 1e18)cout<<-1<<"\n";
    else cout<<dis[n]<<" "<<mnCount[n]<<"\n";



    return 0;
}
