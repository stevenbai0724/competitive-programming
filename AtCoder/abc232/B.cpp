//
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

    string s, t;
    cin>>s>>t;
    int n = s.length();

    for(int i=0;i<26;i++){
        string temp = "";
        for(int j=0;j<n;j++){
            char c = s[j] - 32;
            c += i;
            if(c>'Z')c -= 26;
            c += 32;
            temp += c;
        }

        if(temp == t){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";

    return 0;
}