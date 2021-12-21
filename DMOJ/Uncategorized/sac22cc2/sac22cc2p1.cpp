//
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
    int n, k;
    cin>>n>>k;
    vector<pair<int, string>>arr;
    vector<bool>vis(n);


    for(int i=1;i<=n;i++){
        int x; cin>>x;
        string s; cin>>s;
        arr.push_back({x, s});
    }
    while(k--){
        int x; cin>>x;
        for(int i=0;i<n;i++){
            if(!vis[i] && arr[i].first <= x){
                cout<<arr[i].second<<"\n";
                vis[i] = true;
            }
        }
    }
    

    return 0;
}