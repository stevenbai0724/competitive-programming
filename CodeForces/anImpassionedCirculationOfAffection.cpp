//https://codeforces.com/problemset/problem/814/C
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

    int n; cin>>n;
    string s; cin>>s;
    int q; cin>>q;
    while(q--){
        int m; cin>>m;
        char c ; cin>>c;
        int cur = (s[0] != c ? 1 : 0); //number of non-c characters in sliding substring
        int j = 0;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(j<i){
                j = i;
                cur += (s[j] != c ? 1 : 0);
            }
            if(i>0){
                if(s[i-1]!=c)cur--;
            }
            while(j<n-1 && (cur<m || (cur == m && s[j+1]==c))){
                j++;
                if(s[j]!=c)cur++;
            }

            mx = max(mx, j-i+1);

        }
        cout<<mx<<"\n";
    }

    return 0;
}