//https://cses.fi/problemset/task/1632
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool comp(pair<int, int>a, pair<int, int>b){
    return a.second < b.second;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k; 
    cin>>n>>k;

    multiset<int>endtimes;

    for(int i=1;i<=k;i++)endtimes.insert(0);

    vector<pair<int, int>>arr;
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 0;
    for(auto p: arr){
        auto it = endtimes.upper_bound(p.first);
        if(it == endtimes.begin())continue;
        endtimes.erase(--it);
        endtimes.insert(p.second);
        ans++;
    }

    cout<<ans<<"\n";



    return 0;
}