//https://codeforces.com/contest/320/problem/B
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

    vector<vector<bool>>adj(101, vector<bool>(101));

    vector<pair<int, int>>arr;

    int n; cin>>n;
    while(n--){
        int o, x, y;
        cin>>o>>x>>y;
        if(o == 1){
            arr.push_back({x,y});
            for(int i=0;i<arr.size();i++){
                for(int j=0;j<arr.size();j++){
                    if(i == j)continue;
                    int a = arr[i].first;
                    int b = arr[i].second;
                    int c = arr[j].first;
                    int d = arr[j].second;
                    if(c < a && a < d)adj[i+1][j+1] = true;
                    if(c < b && b < d)adj[i+1][j+1] = true;
                }
            }
        }
        else{
            queue<int>q;
            vector<bool>vis(101);
            vis[x] = true;
            q.push(x);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int i=1;i<=100;i++){
                    if(adj[cur][i] && !vis[i]){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
            cout<<(vis[y] ? "YES\n" : "NO\n");
        }
    }

    return 0;
}