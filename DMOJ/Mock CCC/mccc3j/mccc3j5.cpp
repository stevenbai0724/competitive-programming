//https://dmoj.ca/contest/mccc3j5
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

    int n, m;
    cin>>n>>m;

    vector<pair<int,int>>arr;
    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    int mx = 0;
    for(int i=1;i<(1<<n);i++){
        set<int>s;

        for(int j=0;j<n;j++){
            if((1<<j)&i){
                s.insert(j+1);
            }
        }
        bool good = true;
        for(auto p: arr){
            int x = p.first;
            int y = p.second;
            if(s.find(x)!= s.end() && s.find(y) != s.end())good = false;
        }

        if(good) mx = max(mx,(int)s.size());
        
    }
    cout<<mx<<"\n";

    return 0;
}
