//https://dmoj.ca/problem/ccc21s5
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
    
    void init(int n, vector<int>arr){
        logs.resize(n+1);
        dp.resize(n+1);
        ln = 0;
        for(int i=1;i<=n;i*=2){
            logs[i] = ln;
            ln++;
        }
        for(int i=1;i<=n;i++){
            dp[i].resize(ln+1);
            dp[i][0] = arr[i];
            logs[i] = max(logs[i], logs[i-1]);
        }
        for(int j=1;j<=ln;j++){
            for(int i=1;i + (1<<j)-1 <=n; i++){
                dp[i][j] = __gcd(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l, int r){
        int lg = logs[r-l+1];
        return __gcd(dp[l][lg], dp[r-(1<<lg)+1][lg]);
    }
};
struct edge{
    int x, y, z;
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<edge>res;
    vector<int>ans(n+1,1);

    vector<vector<int>>arr(17, vector<int>(n+2)), pfx(17, vector<int>(n+2));
    for(int i=1;i<=m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        res.push_back({x,y,z});
        arr[z][x]++;
        arr[z][y+1]--;
    }

    for(int i=1;i<=16;i++){
        for(int j=1;j<=n;j++){
            pfx[i][j] = pfx[i][j-1] + arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
       int cnt = 0;
       int lcm;


       for(int j=1;j<=16;j++){
           if(pfx[j][i] > 0){
                cnt++;
                if(cnt == 1)lcm = j;
                else{
                    int p = lcm * j;
                    int GCD = __gcd(lcm, j);
                    lcm = p / GCD;
                }
           }
       }
       if(cnt > 0)ans[i] = lcm;
    }
    bool good = true;
    Sparse sp;
    sp.init(n, ans);
    for(auto e: res){
        int x = e.x;
        int y = e.y;
        int z = e.z;
        if(z != sp.query(x, y))good = false;
        
    }
    if(!good){
        cout<<"Impossible\n";
        return 0;
    }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
 
    

    return 0;
}
