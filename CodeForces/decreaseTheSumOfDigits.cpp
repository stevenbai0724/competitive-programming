//https://codeforces.com/problemset/problem/1409/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int unsigned long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int>pow{1};
    for(int i=1;i<=19;i++){
        pow.push_back(pow[i-1]*10);
    }
    int t; cin>>t;
    while(t--){
        int s, n;
        cin>>s>>n;

        string str = to_string(s);

        int cnt = 0 ;

        for(char c: str){
            cnt += c - '0';
        }

        if(cnt <= n){
            cout<<0<<"\n";
        }
        else{
            int len = str.length();
            int sum = 0;
            for(int i=0; i < len; i++){
                sum += str[i] - '0';
                if(sum >= n){

                    int div = pow[len-i];
                    cout<<pow[len-i] - (s%div)<<"\n";
                    goto nxt;

                }
            }
            nxt:;
        }
    }
    

    return 0;
}
