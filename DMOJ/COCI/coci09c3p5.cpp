//https://dmoj.ca/problem/coci09c3p5
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
//mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, c;
    cin>>n>>c;

    vector<vector<int>>inds(c+1);
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        inds[arr[i]].push_back(i);
    }

    int q; cin>>q;
    while(q--){
        int L, R;
        cin>>L>>R;
        int len = R-L+1;
        int t = 100;
        int found = false;
        int ans = 0;
        while(t--){
            int check = (rng()%len)+L;
            check = arr[check];
            auto it1 = lower_bound(inds[check].begin(), inds[check].end(), L);
            auto it2 = upper_bound(inds[check].begin(), inds[check].end(), R);

            int cnt = it2 - it1;

            if(cnt > len/2){
                found = true;
                ans = check;
                break;
            }
        }
        if(found){
            cout<<"yes "<<ans<<"\n";
        }
        else cout<<"no\n";

    }

    return 0;
}
