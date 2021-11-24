//https://codeforces.com/problemset/problem/1593/B
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
        string s; cin>>s;

        int a = 1e18;
        int b = 1e18;

        int n = s.length();
        for(int i=n-1;i>=1;i--){

            if(s[i] == '0'){
                for(int j=i-1;j>=0;j--){
                    if(s[j] == '5' || s[j] == '0'){
                        a = min(((n-1) - j -1), a);
                        break;
                    }
                }
            }
            if(s[i] == '5'){
                for(int j=i-1;j>=0;j--){
                    if(s[j] == '2' || s[j] == '7'){
                        b = min(b, ((n-1) - j -1));
                        break;
                    }
                }  
            }
            
        }
        cout<<min(a, b)<<"\n";
    }

    return 0;
}