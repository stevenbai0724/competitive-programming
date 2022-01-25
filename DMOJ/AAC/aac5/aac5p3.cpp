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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;

    vector<vector<pair<int, int>>>adj(n+1);
    vector<bool>vis(n+1);
    vector<pair<int, int>>res(n+1);

    res[1] = {1,1e18};

    for(int i=1;i<n;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x].push_back({w,y});
        adj[y].push_back({w,x});
    }

    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }

    queue<int>q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int L1 = res[cur].first;
        int R1 = res[cur].second;
        vector<pair<int, int>>children;

        for(int i=0;i < adj[cur].size();i++){
            int neww = adj[cur][i].first;
            int newy = adj[cur][i].second;
            if(!vis[newy]){
                vis[newy] = true;
                children.push_back({adj[cur][i]});
            }
        }

       
        if(children.empty())continue;
        res[children[0].second].first = 1;

        for(int i=0;i<children.size()-1;i++){
            int curNode = children[i].second;
            int curWeight = children[i].first;
            int nxtNode = children[i+1].second;
            int nxtWeight = children[i+1].first;


            res[curNode].second = (curWeight + nxtWeight )/2;
            res[nxtNode].first = res[curNode].second + 1;
        }
        res[children[children.size()-1].second].second = 1e18;


        for(auto p: children){
            int curNode = p.second;
            int curWeight = p.first;
            int L2 = res[curNode].first;
            int R2 = res[curNode].second;

            if(L1 > R2 || L2 > R1){
                res[curNode] = {-1,-1};
            }
            else{
                res[curNode].first = max(L2, L1);
                res[curNode].second = min(R1, R2);
                q.push(curNode);
            }
        
        }
        
    }
    vector<int>arr(k);
    for(int i=1;i<=k;i++){
        cin>>arr[i-1];
    }
    sort(arr.begin(), arr.end());

    vector<int>ans(n+1);

    for(int i=1;i<=n;i++){
        int L = res[i].first;
        int R = res[i].second;

        if(L == -1 || L == 0){
            ans[i] = 0;
            continue;
        }
        auto hi = upper_bound(arr.begin(), arr.end(), R);
        auto lo = lower_bound(arr.begin(), arr.end(), L);

        ans[i] = hi-lo ;
    }


    cout<<k;
    for(int i=2;i<=n;i++){
        cout<<" "<<ans[i];
    }
    cout<<"\n";

    


    return 0;
}
