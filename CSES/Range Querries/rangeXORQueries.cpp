//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<vector<int>>psa(32, vector<int>(n+1));
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=31;j++){
            psa[j][i] = psa[j][i-1];
        }
        int x; cin>>x;
        arr[i] = x;
        for(int j=0;j<=30;j++){
            if(((int)1<<j)&x){
                psa[j+1][i]++;
            }
        }
    }

    while(q--){
        int x, y;
        cin>>x>>y;
        int ans = 0;
        if(x==y){
            cout<<arr[x]<<"\n";
            continue;
        }

        for(int i=1;i<=31;i++){
            int cnt = psa[i][y]-psa[i][x-1];
            if(cnt&1){
                ans += ((int)1<<(i-1));
            }

        }
        cout<<ans<<"\n";
    }

    return 0;
}