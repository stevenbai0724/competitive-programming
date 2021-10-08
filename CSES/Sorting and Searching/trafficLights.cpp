//https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, n; 
    cin>>x>>n;

    multiset<int>pos{0,x};
    multiset<int>lens{x};
    
    for(int i=1;i<=n;i++){
        int p; cin>>p;
        auto R = pos.lower_bound(p);
        auto L = R; L--;

        lens.erase(lens.find(*R-*L));
        pos.insert(p);
        
        lens.insert(p-*L);
        lens.insert(*R-p);

        auto ans = lens.rbegin();
        cout<<*ans<<" ";

    }
    cout<<"\n";

    return 0;
}