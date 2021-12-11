//https://dmoj.ca/problem/coci08c6p1
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

    string s, t;
    char c;
    cin>>s>>c>>t;

    if(s.length() < t.length())swap(s,t);

    if(c == '*'){
        cout<<1;
        for(int i=1;i<=(s.length()-1) + (t.length()-1);i++){
            cout<<0;
        }
        cout<<"\n";
    }
    else{
        if(s == t){
            cout<<2<<s.substr(1)<<"\n";
        }
        else{
            cout<<s.substr(0,s.length() - t.length())<<t<<"\n";
        }
    }


    return 0;
}