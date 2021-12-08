//https://codeforces.com/contest/762/problem/B
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

    int a, b, c;
    cin>>a>>b>>c;

    int m; cin>>m;

    vector<vector<int>>arr(2);
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        string s; cin>>s;
        if(s == "USB")arr[0].push_back(x);
        else arr[1].push_back(x);
    }
    for(int i=0;i<=1;i++)sort(arr[i].begin(), arr[i].end());
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<min(a, (int)arr[0].size());i++){
        ans += arr[0][i];
        cnt++;
    }
    for(int i=0;i<min(b, (int)arr[1].size());i++){
        ans += arr[1][i];
        cnt++;
    }
    multiset<int>s;
    for(int i=a;i<arr[0].size();i++){
        s.insert(arr[0][i]);
    }
    for(int i=b;i<arr[1].size();i++){
        s.insert(arr[1][i]);
    }
    for(int x: s){
        if(c == 0)break;
        ans += x;
        cnt ++;
        c --;
    }
    cout<<cnt<<" "<<ans<<"\n";

    return 0;
}