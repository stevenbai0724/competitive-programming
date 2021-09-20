//https://cses.fi/problemset/task/1679
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
int n,m;
int ind = 0;
vector<int>ans;
vector<vector<int>>adj;
vector<int>indegree;
bool topoSort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!indegree[i])q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans[ind++] = cur;
        for(int to: adj[cur]){
            indegree[to]--;
            if(!indegree[to])q.push(to);
        }
    }
    return ind==n;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>m;
    adj.resize(n+1);
    ans.resize(n+1);
    indegree.resize(n+1);

    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    if(!topoSort()){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}