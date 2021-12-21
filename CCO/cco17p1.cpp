//https://dmoj.ca/problem/cco17p1
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

    vector<int>arr;

    for(int i=1;i<=4999;i++){
        arr.push_back(i*(i+1)/2);
    }

    int n; cin>>n;

    vector<int>use;

    while(n > 0){
        int nxt = *(--upper_bound(arr.begin(), arr.end(), n));
        
        int ind = (--upper_bound(arr.begin(), arr.end(), n)) - arr.begin();

        n -= nxt;

        use.push_back(ind + 2);

    }

    vector<pair<int, int>>ans;
    int cur = 1;
    for(int nxt: use){
        int target = cur + nxt - 2;
        if(cur != 1){
            ans.push_back({cur, 1});
        }
        
        for(int i = cur; i <= target; i++){
            ans.push_back({i, i+1});
        }
        ans.push_back({cur + nxt - 1, cur});
        cur += nxt;
    }
    cout<<cur-1<<" "<<ans.size()<<"\n";
    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<"\n";
    }

  

    return 0;
}