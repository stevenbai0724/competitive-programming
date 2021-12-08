//http://www.usaco.org/index.php?page=viewproblem2&cpid=1014
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, m, k;
    cin>>n>>m>>k;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        arr[i] = i;
    }

    vector<pair<int, int>>swap;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        swap.push_back({x,y});
    }
    vector<vector<int>>ans;
    while(true){
        for(auto p: swap){
            reverse(arr.begin() + p.first, arr.begin() + 1 + p.second);
        }
        if(ans.size()>1){
            if(ans[0] == arr){
                break;
            }
        }
        ans.push_back(arr);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[(k-1)%ans.size()][i]<<"\n";
    }


    return 0;
}