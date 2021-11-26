//https://dmoj.ca/problem/coci15c5p4
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

    int n, x;
    cin>>n>>x;
    if(n<=2){
        cout<<-1<<"\n";
        return 0;
    }
    if(x > (n-2)*(n-1)/2){
        cout<<-1<<"\n";
    }

    set<int>left, use;

    for(int i=1;i<=n-2;i++){
        left.insert(i);
    }

    for(int i=n-2;i>=1;i--){
        if(x>=i){
            x -= i;
            int val = n-i-1;
            left.erase(val);
            use.insert(val);
        }
    }
    for(int m: left)cout<<m<<" ";
    cout<<n-1<<" ";
    for(int m: use)cout<<m<<" ";
    cout<<n<<"\n";

    return 0;
}