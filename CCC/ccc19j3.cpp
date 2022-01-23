//https://dmoj.ca/problem/ccc19j3
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
        string s; cin>>s;
        int n = s.length();

        for(int i=0;i<n;i++){
            int j = i;
            while(j<n-1 && s[j+1] == s[j]){
                j++;
            }
            cout<<j-i+1<<" "<<s[j]<<" ";
            i = j;
        }
        cout<<"\n";
    }

    return 0;
}
