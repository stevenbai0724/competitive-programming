//https://dmoj.ca/problem/nccc10s1
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

    set<string>arr;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        arr.insert(s);
    }
    int mx = 0;
    for(int i=0;i<(1<<k);i++){
        int cnt = 1e18;
        string ans = "";

        for(int j=0;j<k;j++){
            if((1<<j)&i)ans += 'F';
            else ans += 'T';
        }
        for(auto nxt: arr){
            int cur = 0;
            for(int l=0;l<k;l++){
                if(nxt[l] == ans[l])cur++;
            }
            cnt = min(cnt, cur);
        }
        mx = max(mx, cnt);
    }
    cout<<mx<<"\n";
    return 0;
}