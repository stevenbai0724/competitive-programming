//https://cses.fi/problemset/task/1634/
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
const int INF = 1e18;
vector<bool>vis(1e6+2);
vector<int>dp(1e6+2);
vector<int>first(1e6+2);
vector<int>coins;
int solve(int x){
    if(x < 0)return INF;
    if(x == 0)return 0;
    if(vis[x])return dp[x];
    int ans = 1e18;
    for(int c: coins){
        int nxt = solve(x-c) + 1;
        if( nxt < ans){
            ans = nxt;
            first[x] = c;
        }
    }
    vis[x] = true;
    dp[x] = ans;
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        coins.push_back(x);
    }
    cout<<(solve(k) == 1e18 ? -1 : dp[k])<<"\n";

    while(k > 0){
        cout<<first[k]<<" ";
        k -= first[k];
    }

    cout<<"\n";
    

    return 0;
}
