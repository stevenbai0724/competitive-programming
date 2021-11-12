//http://www.usaco.org/index.php?page=viewproblem2&cpid=572
//USACO 2015 December Contest Silver P2
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

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin>>n>>q;
    vector<vector<int>>psa(4, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        psa[1][i] = psa[1][i-1];
        psa[2][i] = psa[2][i-1];
        psa[3][i] = psa[3][i-1];
        psa[x][i]++;
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<psa[1][b]-psa[1][a-1]<<" "<<psa[2][b]-psa[2][a-1]<<" "<<psa[3][b]-psa[3][a-1]<<"\n";
    }


    return 0;
}