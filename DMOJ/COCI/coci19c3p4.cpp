//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long
int mxn = 3001; // please change

vector<vector<int>>adj(mxn+1);
vector<vector<string>>ans(mxn+1, vector<string>(mxn+1)); 
vector<char>val(mxn+1);
int MX = 1;
void check(string one, string two){

    if(one == two){
        MX = max(MX, (int)one.length());
    }

}
void dfs(int i, int u, int p){
    for(int nxt: adj[u]){
        if(p == nxt)continue;
        ans[i][nxt] = ans[i][u] + val[nxt];
        dfs(i, nxt, u);
    }
    return;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    for(int i=1;i<=n;i++){
        char c = s[i-1];
        val[i] = c;
        ans[i][i] = c;
    }

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        dfs(i, i, 0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            check(ans[i][j], ans[j][i]);
        }
    }
    cout<<MX<<"\n";




    return 0;
}