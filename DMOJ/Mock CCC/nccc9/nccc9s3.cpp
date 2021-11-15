//
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

    int n; cin>>n;
    n*=2;
    string s; cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        int j = i;
        if(s[i]=='I')continue;
        while(j<n-1 && s[j+1]=='U'){
            j++;
        }
        ans += j-i;
        i = j;
    }
    if(s[0]=='U')ans++;

    cout<<ans<<"\n";

    return 0;
}