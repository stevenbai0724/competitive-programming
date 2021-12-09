//https://codeforces.com/problemset/problem/1490/B
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

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        int a = 0;
        int b = 0;
        int c = 0;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            x%=3;
            a += x == 0;
            b += x == 1;
            c += x == 2;
        }
        int target = (a+b+c)/3;

        int cnt = 0;
        while(!(a==target && b==target && c==target)){
            if(a>=target){
                cnt += a-target;
                b += a-target;
                a = target;
            }
            if(b>=target){
                cnt += b-target;
                c += b-target;
                b = target;
            }
            if(c>=target){
                cnt += c-target;
                a += c-target;
                c = target;
            }
        }
        cout<<cnt<<"\n";

    }


    return 0;
}