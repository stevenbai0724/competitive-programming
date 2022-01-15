//https://dmoj.ca/problem/naq16c
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
    int w, y;
};
class Compare{
  public:
    bool operator() (edge a, edge b){
        return a.w > b.w;
    }
};

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>val(n+1);

    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<vector<edge>>adj(n+1);

    vector<int>dis(n+1, 1e18), weight(n+1, -1e18);

    int m; cin>>m;

    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    priority_queue<edge, vector<edge>, Compare>q;

    q.push({0,1});
    dis[1] = 0;
    weight[1] = val[1];

    while(!q.empty()){
        int y = q.top().y;
        q.pop();

        for(edge e: adj[y]){
            int neww = e.w;
            int newy = e.y;

            if(dis[newy] > neww + dis[y]){
                dis[newy] = neww + dis[y];
                weight[newy] = weight[y] + val[newy];
                q.push({dis[newy], newy});
            }
            else if (dis[newy] == neww + dis[y]){
                if(weight[newy] < weight[y] + val[newy]){
                    weight[newy] = weight[y] + val[newy];
                    q.push({dis[newy], newy});
                }
            }
        }
    }   


    if(dis[n] == 1e18)cout<<"impossible\n";
    else cout<<dis[n]<<" "<<weight[n]<<"\n";






    return 0;
}
