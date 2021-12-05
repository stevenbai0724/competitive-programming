//https://codeforces.com/contest/1614/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
bool comp(pair<int, int>a, pair<int, int>b){
    return a.first>b.first;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int, int>>arr(n);

        for(int i=0;i<n;i++){
            int x; cin>>x;
            arr[i] = {x,i};
        }
        vector<int>ans(n);
        sort(arr.begin(), arr.end(), comp);
        int turn = 1;
        int cnt = 0;
        for(auto p: arr){
            int cur = p.first;
            int ind = p.second;
            if(turn&1){
                ans[ind] = (turn/2 +1);
                cnt += ans[ind] * 2 * cur;
            }
            else{
                ans[ind] = (turn/-2);
                cnt += ans[ind] * -2 * cur;
            }
            turn++;
        }
        cout<<cnt<<"\n"<<"0 ";
        for(int x: ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}