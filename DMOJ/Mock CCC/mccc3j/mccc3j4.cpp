//https://dmoj.ca/contest/mccc3j4
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

    int n, t;
    cin>>n>>t;
    vector<queue<int>>adj(n+1);
    vector<int>last(n+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        adj[i].push(x);
    }

    while(t--){
        vector<vector<int>>add(n+1);
        for(int i=1;i<=n;i++){
            if(adj[i].empty())continue;
            int cur = adj[i].front();
            adj[i].pop();
            last[i] = cur;
            add[cur].push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(!add[i].empty()){
                for(int x: add[i]){
                    adj[i].push(x);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<last[i];
        if(i<n)cout<<" ";
    }
    cout<<"\n";

    return 0;
}
