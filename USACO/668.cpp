//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
//USACO 2016 December Contest Silver P3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
struct edge{
    int x, y, w, i ;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin>>n;

    vector<edge>arr{{-1,-1,-1}};

    for(int i=1;i<=n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        arr.push_back({x,y,w,i});
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        vector<int>vis(n+1);

        queue<edge>q;

        q.push(arr[i]);
        vis[i] = true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int j=1;j<=n;j++){
                int newx = arr[j].x;
                int newy = arr[j].y;
                int neww = arr[j].w;
                if(j == cur.i)continue;
                if(vis[j])continue;
                if(cur.w * cur.w < abs(newx-cur.x) * abs(newx-cur.x) + abs(newy-cur.y) * abs(newy-cur.y) ) continue;
                vis[j] = true;
                q.push(arr[j]);
            }
        }
        mx = max(mx, (int)count(vis.begin(), vis.end(), true));
    }
    cout<<mx<<"\n";


    return 0;
}