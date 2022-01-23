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

    int n, q;
    cin>>n>>q;

    vector<vector<int>>anc(30, vector<int>(n+1));
    for(int i=2;i<=n;i++){
        cin>>anc[0][i];
    }

    for(int i=1;(1<<i) <= n; i++){
        for(int j=2;j<=n;j++){
            int nxt = anc[i-1][j];
            anc[i][j] = anc[i-1][nxt];
        }
    }

    while(q--){
        int x, k;
        cin>>x>>k;
        int ans = x;
        for(int i=0;(1<<i)<=n;i++){
            if((1<<i)&k){
                ans = anc[i][ans];
            }
        }
        if(ans == 0)cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }



    return 0;
}
