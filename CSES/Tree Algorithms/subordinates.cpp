//https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string
int n;
vector<vector<int>>child;
vector<int>treeSize;
void dfs(int v){
    for(int u: child[v]){
        dfs(u);
        treeSize[v]+= treeSize[u];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n;
    child.resize(n+1);
    treeSize.resize(n+1);
    fill(treeSize.begin(), treeSize.end(), 1);

    for(int i=2;i<=n;i++){
        int x; cin>>x;
        child[x].push_back(i);
    }
    dfs(1);

    for(int i=1;i<=n;i++){
        cout<<treeSize[i]-1<<" ";
    }

    return 0;
}