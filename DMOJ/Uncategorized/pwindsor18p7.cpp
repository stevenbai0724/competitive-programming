//https://dmoj.ca/problem/pwindsor18p7
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

bool comp(string a, string b){
    return (a+b > b+a);
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<string>arr;
    while(n--){
        string s; cin>>s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), comp);
    string ans = "";
    for(auto s: arr)ans += s;
    cout<<ans<<"\n";


    return 0;
}