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

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1, vector<int>(n+1));
    vector<vector<int>>dis(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = 1e18;
            adj[i][j] = 1e18;

        }
    }

    for(int i=1;i<=m;i++){
        int x, y, w;
        cin>>x>>y>>w;
        adj[x][y] = min(adj[x][y], w);
    }
    int k, q;
    cin>>k>>q;

    vector<int>perm;
    for(int i=1;i<=n;i++){
        perm.push_back(i);
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int a = perm[i];
            int b = perm[j];

            int len = abs(i-j);
            if(len <= k){
                int sum = 0;
                for(int l=i;l<j;l++){
                    int x = perm[l];
                    int y = perm[l+1];
                    sum += adj[x][y];
                }
                dis[a][b] = min(dis[a][b], sum);
            }
        }
    }

    while(next_permutation(perm.begin(), perm.end())){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a = perm[i];
                int b = perm[j];

                int len = abs(i-j);
                if(len <= k){
                    int sum = 0;
                    for(int l=i;l<j;l++){
                        int x = perm[l];
                        int y = perm[l+1];
                        sum += adj[x][y];
                    }
                    dis[a][b] = min(dis[a][b], sum);
                }
            }
        }
    }

    while(q--){
        int x, y;   
        cin>>x>>y;
        if(x == y){
            cout<<0<<"\n";
            continue;
        }
        if(dis[x][y] == 1e18)cout<<-1<<"\n";
        else cout<<dis[x][y]<<"\n";
    }



    

    return 0;
}
