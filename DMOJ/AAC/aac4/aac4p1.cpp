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

    int n, m;
    cin>>n>>m;
    string s; cin>>s;
    string temp = s;
    s = temp + temp;

    vector<int>arr(m+1);

    int mx = 0;
    int thZero = 0;
    for(int i=1;i<=m;i++){
        cin>>arr[i];
        if(arr[i] >= mx){
            thZero = i;
            mx = arr[i];
        }
    }
    int ind;
    int cur = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            cur++;
        }
        if(cur == thZero){
            ind = i;
            break;
        }
    }
    string ans = "";

    for(int i=ind+1;ans.length()<(n-m);i++){
        if(s[i]!='0')ans += s[i];
    }

    cout<<ans<<"\n";


    return 0;
}   