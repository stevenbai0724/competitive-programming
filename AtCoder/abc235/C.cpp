//https://atcoder.jp/contests/abc235/tasks/abc235_c
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
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    map<int, int>mp, mp2;
    vector<int>arr(n+1);
    vector<int>vals;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(mp[arr[i]] == 0){
            vals.push_back(arr[i]);
        }
        mp[arr[i]]++;
    }
    vector<vector<int>>inds(vals.size());
    sort(vals.begin(), vals.end());

    for(int i =1;i<=n;i++){
        int rank = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
        inds[rank].push_back({i});
    }

    while(q--){
        int x, k;
        cin>>x>>k;
        if(mp[x] < k){
            cout<<-1<<"\n"; 
        }
        else{
            int rank = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            cout<<inds[rank][k-1]<<"\n";
        }
    }
    

    

    return 0;
}
