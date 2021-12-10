//https://codeforces.com/problemset/problem/515/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool comp(char c, char d){
    return c > d;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;

    string ans = "";

    for(char c: s){
        if(c!='0' && c!= '1'){
            if(c == '4')ans += "322";
            else if(c == '6')ans += "53";
            else if(c == '8')ans += "7222";
            else if (c == '9')ans += "7332";
            else ans += c;
        }
    }
    sort(ans.begin(), ans.end(), comp);
    cout<<ans<<"\n";


    return 0;
}