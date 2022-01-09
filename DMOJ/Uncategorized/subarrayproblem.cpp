//https://dmoj.ca/problem/subarrayproblem
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

    int n; cin>>n;

    vector<int>ind(n+1);

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        ind[x] = i;
    }
    set<int>s;
    int ans = 0;
    for(int i=1;i<=n;i++){
        s.insert(ind[i]);

        int L = *s.begin();
        int R = *s.rbegin();

        if(R-L+1 == i)ans++;

    }
    cout<<ans<<"\n";

    return 0;
}
