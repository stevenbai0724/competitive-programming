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

    int n; cin>>n;
    string s; cin>>s;

    for(int i=0;i<n-1;i++){
        if(s[i+1] > s[i]){
            char temp = s[i+1];
            s[i+1] = s[i];
            s[i] = temp;
            cout<<s<<"\n";
            return 0;
        }
    }
    cout<<s<<"\n";


    return 0;
}
