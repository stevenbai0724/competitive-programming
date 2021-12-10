//https://dmoj.ca/problem/coci14c3p1
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

    vector<int>ans(8);
    vector<string>arr(8);
    arr[0] = "1QAZ";
    arr[1] = "2WSX";
    arr[2] = "3EDC";
    arr[3] = "4RFV5TGB";
    arr[4] = "6YHN7UJM";
    arr[5] = "8IK,";
    arr[6] = "9OL.";
    arr[7] = "0P;/-['=]";

    string s; cin>>s;

    for(char c: s){
        assert(c!='`');
        for(int i=0;i<8;i++){
            for(auto nxt : arr[i]){
                if (nxt == c)ans[i]++;
            }
        }
    }
    for(int x: ans)cout<<x<<"\n";



    return 0;
}