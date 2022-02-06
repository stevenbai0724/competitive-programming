//https://dmoj.ca/problem/coci19c1p2
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
bool prime(int x){
    if(x <= 1)return false;
    bool ans = true;
    for(int i=2;i*i<=x;i++){
        if(x%i == 0)return false;
    }
    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b;
    cin>>a>>b;
    
    set<int>s{a,b};
    vector<int>nums{0};

    s.insert(2);
    if(prime(a+2))s.insert(a+2);
    if(prime(a-2))s.insert(a-2);
    if(prime(b+2))s.insert(b+2);
    if(prime(b-2))s.insert(b-2);

    for(int x: s)nums.push_back(x);

    int sz = nums.size()-1;

    vector<vector<int>>adj(sz+1);
    int START, END;
    for(int i=1;i<sz;i++){
        for(int j=i+1;j<=sz;j++){
            if(i == j)continue;
            if(!prime(abs(nums[i] - nums[j])))continue;
            adj[i].push_back(j);
            adj[j].push_back(i);

        }
    }

    for(int i=1;i<=sz;i++){
        if(nums[i] == a)START = i;
        if(nums[i] == b)END = i;
    }

    queue<int>q;
    vector<bool>vis(10);
    vector<int>dis(10);
    vector<int>parent(10);


    vis[START] = true;
    q.push(START);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                parent[nxt] = cur;
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
    if(!vis[END]){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int>ans;
    int cur = END;

    while(cur!=0){
        ans.push_back(nums[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());


    cout<<ans.size()<<"\n";

    for(int x: ans)cout<<x<<" ";
    cout<<"\n";

    
    return 0;
}
