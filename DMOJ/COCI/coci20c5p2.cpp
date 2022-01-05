//https://dmoj.ca/problem/coci20c5p2
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

    int n; cin>>n;  
    stack<int>s;
    int ans = 1;
    int num; cin>>num;
    s.push(num);
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        while(!s.empty() && s.top() > x){
            s.pop();
        }
        if((!s.empty() && s.top() == x)){
            continue;
        }
        else if(x!=0){
            ans++;
            s.push(x);
        }
        


    }
    cout<<ans<<"\n";

    return 0;
}
