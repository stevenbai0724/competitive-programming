//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;
    vector<int>arr(m*2 + 3);

    vector<pair<int, int>>intervals(n+1);

    for(int i=1;i<=n;i++){
        cin>>intervals[i].first>>intervals[i].second;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a = intervals[i].first + intervals[j].first;
            int b = intervals[i].second + intervals[j].second;
            arr[a]++;
            arr[b+1]--;
        }
    }
    vector<int>psa(m*2 + 3);

    for(int i=0;i<=m*2;i++){
        if(i>0)psa[i] = psa[i-1];
        psa[i] += arr[i];
    }
    for(int i=0;i<=m*2;i++){
        cout<<psa[i]<<"\n";
    }


    return 0;
}