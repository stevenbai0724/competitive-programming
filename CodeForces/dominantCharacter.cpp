//https://codeforces.com/problemset/problem/1605/C
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
        int n; cin>>n;
        string s; cin>>s;
        for(int i=0;i<n-1;i++){
            if(s.substr(i,2) == "aa"){
                cout<<2<<"\n";
                goto nxt;
            }
        }
        for(int i=0;i<n-2;i++){
            if(s.substr(i,3) == "aba" || s.substr(i,3) == "aca"){
                cout<<3<<"\n";
                goto nxt;
            }
        }
        for(int i=0;i<n-3;i++){
            if(s.substr(i,4) == "abca" || s.substr(i,4) == "acba"){
                cout<<4<<"\n";
                goto nxt;
            }
        }
        for(int i=0;i<n-6;i++){
            if(s.substr(i,7) == "accabba" || s.substr(i,7) == "abbacca"){
                cout<<7<<"\n";
                goto nxt;
            }
        }

        cout<<-1<<"\n";
        nxt:;
    }

    return 0;
}
