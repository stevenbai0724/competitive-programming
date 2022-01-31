//https://cses.fi/problemset/task/1647
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
struct Sparse{
    vector<int>logs;
    vector<vector<int>>dp;

    int ln, size;

    void init(int n, vector<int>arr){
        size = n;
        ln = 0;
        logs.resize(n+1);
        for(int i=1;i<=n;i*=2){
            logs[i] = ln;
            ln++;
        }
        dp.resize(ln+1);

        for(int i=0;i<=ln;i++){
            dp[i].resize(n+1);
        }
        for(int i=1;i<=n;i++){
            logs[i] = max(logs[i], logs[i-1]);
            dp[0][i] = arr[i];
        }
        for(int i=1;i<=ln;i++){
            for(int j=1; j + (1<<i)-1 <=n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
            }
        }

    }
    int query(int l, int r){
        int lg = logs[r-l+1];
        return min(dp[lg][l], dp[lg][r - (1<<lg) + 1]);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    Sparse sp;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sp.init(n, arr);
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<sp.query(x, y)<<"\n";
    }
    

    return 0;
}
