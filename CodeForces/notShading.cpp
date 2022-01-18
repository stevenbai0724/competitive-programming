//
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
        int n, m, r, c;
        cin>>n>>m>>r>>c;
    
        bool found = false;
        bool one = false;
        bool zero = false;
        for(int i=1;i<=n;i++){
            string s; cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1] == 'B'){
                    if(j == c || i == r)one = true;
                    if(j == c && i == r)zero = true;
                    found = true;
                }
            }
        }
        if(!found)cout<<-1<<"\n";
        else if(zero)cout<<0<<"\n";
        else if(one)cout<<1<<"\n";
        else cout<<2<<"\n";
    }

    return 0;
}
