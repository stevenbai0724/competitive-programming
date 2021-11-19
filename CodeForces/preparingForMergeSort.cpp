//https://codeforces.com/contest/847/problem/B
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

    int n; cin>>n;
    vector<vector<int>>ans;
    int mn = 1e18;
    for(int i=1;i<=n;i++){
        int x; cin>>x;

        if(i==1){
            ans.push_back({x});
            continue;
        }

        int L = -1;
        int R = ans.size() - 1;

        while(L+1<R){
            int m = (L+R)/2;

            if(ans[m][ans[m].size()-1]>x)L = m;
            else R = m;
        }
        if(ans[R][ans[R].size()-1]>x)ans.push_back({x});
        else ans[R].push_back(x);
    
    }
    for(auto v: ans){
        for(int x: v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}