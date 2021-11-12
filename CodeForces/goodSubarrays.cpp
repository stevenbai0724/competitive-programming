//https://codeforces.com/contest/1398/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>psa(n+1);

        string s; cin>>s;
        map<int, int>mp;
        mp[0]++;
        int ans = 0;
        for(int i=0;i<n;i++){
            psa[i+1] = psa[i];
            psa[i+1] += s[i]-'0';
            ans += mp[psa[i+1]-i-1];
            mp[psa[i+1]-i-1]++;
        }
        cout<<ans<<"\n";
        

    }


    return 0;
}