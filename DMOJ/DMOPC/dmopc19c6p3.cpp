//https://dmoj.ca/problem/dmopc19c6p3
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

    int n, m;
    cin>>n>>m;
    const int mod = 1e9 + 7;
    string s; cin>>s;

    vector<int>pow2(5e5+1);

    pow2[0] = 1;

    for(int i=1;i<=5e5;i++){
        pow2[i] = pow2[i-1]*2;
        pow2[i] %= mod;
    }

    int ans = 0;
    set<int>ind;
    ind.insert(-1);
    ind.insert(1e18);
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ans += pow2[n-i-1];
            ans %= mod;
        }
        else ind.insert(i+1);
    }

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        
        auto it = ind.lower_bound(x);

        while(*it <= y){
            ans += pow2[n-*it];
            ans %= mod;
            ind.erase(it);
            it = ind.lower_bound(x);
        }
        cout<<ans%mod<<"\n";    
    }
    
    return 0;
}