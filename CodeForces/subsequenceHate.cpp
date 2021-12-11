//https://codeforces.com/problemset/problem/1363/B
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

    int t; cin>>t;

    while(t--){
        string s; cin>>s;
        int n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0')cnt++;
        }
        int ans = min(n-cnt, cnt);
        vector<vector<int>>pfx(2, vector<int>(n+1)), sfx(2, vector<int>(n+1));

        for(int i=0;i<n;i++){
            if(i>=1){
                pfx[0][i] = pfx[0][i-1];
                pfx[1][i] = pfx[1][i-1];
            }
            if(s[i] == '1')pfx[1][i]++;
            else pfx[0][i]++;
        }
        for(int i=n-1;i>=0;i--){

            sfx[0][i] = sfx[0][i+1];
            sfx[1][i] = sfx[1][i+1];
  
            if(s[i] == '1')sfx[1][i]++;
            else sfx[0][i]++;
        }

        for(int i=0;i<n-1;i++){
            ans = min(ans, min(pfx[0][i] + sfx[1][i+1], pfx[1][i] + sfx[0][i+1]));
        }
        cout<<ans<<"\n";


    }

    return 0;
}