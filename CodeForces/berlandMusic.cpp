//https://codeforces.com/problemset/problem/1622/B
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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>arr(n+1), ind(n+1), ans(n+1);

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            ind[arr[i]] = i;
        }
        set<pair<int, int>>st;
        string s; cin>>s;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                st.insert({0,arr[i+1]});
            }
            else{
                st.insert({1,arr[i+1]});
            }
        }
        int cnt = 1;
        for(auto p: st){
            int val = p.second;
            int index = ind[val];
            ans[index] = cnt;

            cnt++;
        }

        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<"\n";

        
    }

    return 0;
}
