//https://codeforces.com/problemset/problem/1492/C
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
    string s, t;
    cin>>s>>t;

    vector<int>leftmost(m+1), rightmost(m+1);

    int j = 0;
    for(int i=0;i<n;i++){
        if(s[i] == t[j]){
            leftmost[j] = i;
            j++;
        }
    }
    j = m-1;

    for(int i=n-1;i>=0;i--){
        if(s[i] == t[j]){
            rightmost[j] = i;
            j--;
        }
    }
    int ans = 0;
    for(int i=0;i<m-1;i++){
        ans = max(ans, rightmost[i+1] - leftmost[i]);
    }
    cout<<ans<<"\n";


    return 0;
}