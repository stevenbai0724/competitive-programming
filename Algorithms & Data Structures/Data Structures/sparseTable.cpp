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
struct Sparse{
    vector<int>logs;
    vector<vector<int>>dp;
    int ln;
    int size;
    void init(int n, vector<int>arr){
        size = n;
        logs.resize(n+1);
        dp.resize(n+1);
        ln = 0;
        for(int i = 1; i<=n; i*=2){
            logs[i] = ln; ln++;
        }
        for(int i = 1; i<=n; i++){
            dp[i].resize(ln+1);
            logs[i] = max(logs[i],logs[i-1]);
            dp[i][0] = arr[i];
        }
        for(int i = 1; i<=ln; i++){
            for(int j = 1; j+(1<<i)-1<=n; j++){
                dp[j][i] = min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
    }
    int query(int l, int r){
        int lg = logs[r-l+1];
        return min(dp[l][lg],dp[r-(1<<lg)+1][lg]);
    }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    return 0;
}
