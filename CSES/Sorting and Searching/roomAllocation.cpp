//https://cses.fi/problemset/task/1164
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
struct edge{
    int a, b, id;
};
bool comp(edge a, edge b){
    return a.a<b.a;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<edge>arr;
    for(int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        arr.push_back({a,b,i});
    }
    sort(arr.begin(), arr.end(), comp);

    int room = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    vector<int>ans(n+1);
    int mx = 0;
    for(auto e: arr){
        if(q.empty()){
            room ++;
            q.push({e.b, room});
            ans[e.id] = room;

        }
        else{
            int mn = q.top().first;
            int rm = q.top().second;
            if(mn < e.a){
                q.pop();
                q.push({e.b, rm});
                ans[e.id] = rm;
            }
            else{
                room ++;
                q.push({e.b, room});
                ans[e.id] = room;
            }
        }
        mx = max(mx, (int)q.size());
    }
    cout<<mx<<"\n";

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    
    

    return 0;
}