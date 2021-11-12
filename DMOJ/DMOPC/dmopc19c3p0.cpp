//https://dmoj.ca/problem/dmopc19c3p0
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

    int t; cin>>t;
    while(t--){

        vector<int>arr(11);
        vector<int>emt(11, 0);
        bool zero = false;
        for(int i=1;i<=10;i++){
            cin>>arr[i];
            if(arr[i]==0)zero = true;
        }
 
        bool add = true;
        bool mult = true;

        for(int i=1;i<=8;i++){
            add = add && (arr[i]+arr[i+2] == arr[i+1]*2);
            mult = mult && (arr[i]*arr[i+2] == arr[i+1]*arr[i+1]);
        }

        if(add && mult)cout<<"both\n";
        else if(add)cout<<"arithmetic\n";
        else if(mult)cout<<"geometric\n";
        else cout<<"neither\n";
    }


    return 0;
}