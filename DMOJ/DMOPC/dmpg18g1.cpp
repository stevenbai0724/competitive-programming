//https://dmoj.ca/problem/dmpg18g1
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
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1
    // -13 -12 -11 -6 -5 -4

    vector<int>emptyChairs(k+1);

    for(int i=1;i<=k;i++){
        cin>>emptyChairs[i];
    }
    set<int>s;
    gp_hash_table<int, int>ind;
    for(int i=1;i<=k+1;i++){
        int x; cin>>x;
        ind[x] = i;

        s.insert(-x);
        s.insert(-x-n);
    }

    for(int i=1;i<=k;i++){
        int a = -emptyChairs[i];
        int b = a - n;

        auto nxt = lower_bound(s.begin(), s.end(), a);

        if(nxt == s.end())nxt = lower_bound(s.begin(), s.end(), b);

        int found = *nxt;
        if(abs(found) > n)found+=n;

        s.erase(found);
        s.erase(found-n);
    }
    assert(s.size() == 2);
    int ans = abs(*s.begin()) % n;
    if(ans == 0)ans = n;

    cout<<ind[ans]<<"\n";



    return 0;
}
