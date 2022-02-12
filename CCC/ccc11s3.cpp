//https://dmoj.ca/problem/ccc11s3
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
vector<int>power{1,5};
bool solve(int m, int x, int y){
    int sublen = power[m-1];

    int x1 = x % sublen;
    int y1 = y % sublen;

    pair<int, int>pp = {x/sublen,y/sublen};

    if(pp == pair<int, int>{1,0} || pp == pair<int, int>{2,0} || pp == pair<int, int>{3,0} || pp == pair<int, int>{2,1})return true;
    if(m > 1){
        if(pp == pair<int, int>{1,1} || pp == pair<int, int>{2,2} || pp == pair<int, int>{3,1}){
            return solve(m-1, x1, y1);
        }
        else return false;
    }
    return false;

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=1;i<=14;i++){
        power.push_back({power[i]*5});
    }
    int t; cin>>t;
    while(t--){
        int m, x, y;
        cin>>m>>x>>y;
        if(solve(m, x, y))cout<<"crystal\n";
        else cout<<"empty\n";
    }


    return 0;
}
