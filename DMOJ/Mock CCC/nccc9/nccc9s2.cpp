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
    vector<int>U;
    vector<int>I;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]=='U'){
                U.push_back(i);
            }
        }
        else{
            if(s[i]=='I'){
                I.push_back(i);
            }
        }
    }
    int m = U.size();
    assert(U.size()==I.size());

    for(int i=0;i<m;i++){
        ans += abs(U[i] - I[i]);
    }

    cout<<ans<<"\n";

    return 0;
}