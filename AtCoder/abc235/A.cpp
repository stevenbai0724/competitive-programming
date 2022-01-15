//https://atcoder.jp/contests/abc235/tasks/abc235_a
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

    string s; cin>>s;

    char a = s[0];
    char b = s[1];
    char c = s[2];

    string t = "";
    string u = "";
    t += b;
    t += c;
    t += a;
    u += c;
    u += a;
    u += b;

    int ans = stoi(s) + stoi(t) + stoi(u);
    cout<<ans<<"\n";

    return 0;
}
