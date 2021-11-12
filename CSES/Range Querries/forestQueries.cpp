//https://cses.fi/problemset/task/1652
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
    vector<vector<int>>arr(n+1, vector<int>(n+1));
    vector<vector<int>>psa(n+1, vector<int>(n+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            arr[i][j] = s[j-1] == '*';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            psa[i][j] = arr[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        cout<<psa[c][d] - psa[c][b-1] - psa[a-1][d] + psa[a-1][b-1]<<"\n";
    }

    return 0;
}