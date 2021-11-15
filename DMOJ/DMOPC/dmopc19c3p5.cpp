//https://dmoj.ca/problem/dmopc19c3p5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin>>n>>q;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }

    while(q--){
        int o, y;
        cin>>o>>y;
        if(o==1){
            arr.push_back(y);
        }
        else if(o==2){
            for(int &x : arr){
                x += y;
            }
        }
        else{
            int ans = 0;
            for(int x : arr){
                int num  = abs(x%y);
                ans += min(y-num, num);
            }
            cout<<ans<<"\n";
        }
    }
    

    return 0;
}