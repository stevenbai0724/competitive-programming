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

    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        cords[i] = {x,y};
    }
    int START; cin>>START;

    vector<int>dis(n+1, (int)1e18); 
    vector<bool>vis(n+1);
    dis[0] = 0;
    dis[START] = 0;
    int nxt = START;
    pair<int, int>mn = {(int)1e18, START};

    for(int i=1;i<n;i++){
        vis[nxt] = true;
        mn = {(int)1e18, 0};
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            int a = abs(cords[nxt].first - cords[j].first);
            int b = abs(cords[nxt].second - cords[j].second);
            int val = (a*a) + (b*b) + dis[nxt];

            if(dis[j] > val){
                dis[j] = val;
            }
            mn = min(mn,{dis[j], j});

        }
        nxt = mn.second;
    }
    sort(dis.begin(), dis.end());

    int q; cin>>q;
    while(q--){
        int x; cin>>x;

        cout<<upper_bound(dis.begin(), dis.end(), x) - dis.begin() -1<<"\n";
    }

    return 0;
}