//https://dmoj.ca/problem/wc17c3j3
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

    int a = 0;
    int b = 0;
    int c = 0;
    string s; cin>>s;

    for(char ch: s){
        if(ch >= 'a' && ch <= 'z')a++;
        else if(ch >= 'A' && ch<='Z')b++;
        else{
            c++;
            assert(ch >= '0' && ch<='9');
        }
    }
    if(a >= 3 && b>=2 && c >= 1 && s.length() >=8 && s.length() <=12 )cout<<"Valid\n";
    else cout<<"Invalid\n";

    return 0;
}