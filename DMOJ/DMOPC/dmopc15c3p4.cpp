//https://dmoj.ca/problem/dmopc15c3p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<pair<int, int>>cords(n+1);
    vector<vector<pair<int, int>>>adj(n+1);
    vector<int>dis(n+1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        cords[i] = {x,y};
    }
    int START; cin>>START;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int a = abs(cords[i].first - cords[j].first);
            int b = abs(cords[i].second - cords[j].second);

            adj[i].push_back({(a*a) + (b*b), j});
        }
    }
    dis[START] = 0;
    q.push({0, START});

    while(!q.empty()){
        int w = q.top().first;
        int y = q.top().second;
        q.pop();
        if(dis[y] < w) continue;
        for(auto nxt: adj[y]){
            int neww = nxt.first;
            int newy = nxt.second;
            if(neww + dis[y] < dis[newy]){
                dis[newy] = neww + dis[y];
                q.push({dis[newy], newy});
            }
        }
    }
    sort(dis.begin(), dis.end());

    int t; cin>>t;
    while(t--){
        int x; cin>>x;

        int L = 0;
        int R = n;

        while(L+1<R){
            int m = (L+R)/2;
            if(dis[m]<=x)L = m;
            else R = m;
        }
        cout<<R<<"\n";

    }


    return 0;
}