//https://atcoder.jp/contests/abc237/tasks/abc237_c
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
bool good(string s){
    bool ans = true;
    int n = s.length();

    for(int i=0;i<n;i++){
        if(s[i] != s[n-1-i])ans = false;
    }

    return ans;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int n = s.length();

    if(good(s)){
        cout<<"Yes\n";
        return 0;
    }

    int L, R;

    for(int i=0;i<n;i++){
        if(s[i] != 'a'){
            L = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]!= 'a'){
            R = i;
            break;
        }
    }
    int len = R-L+1;

    if(!good(s.substr(L, len))){
        cout<<"No\n";
    }
    else{
        R = n-1-R;
        if(R >= L)cout<<"Yes\n";
        else cout<<"No\n";
    }


    return 0;
}
