//https://codeforces.com/problemset/problem/1400/C
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

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int x; cin>>x;
        int n = s.length();

        string og = "";
        for(int i=1;i<=n;i++){
            og += "1";
        }

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                if(i-x >=0)og[i-x] = '0';
                if(i+x <n)og[i+x] = '0';
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                bool good = false;
                if(i-x>=0)good |= (og[i-x] == '1');
                if(i+x<n)good |= (og[i+x] == '1');
                if(!good){
                    cout<<-1<<"\n";
                    goto nxt;
                }
            }
        }
        cout<<og<<"\n";

        nxt:;


    }

    return 0;
}