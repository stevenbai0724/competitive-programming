//https://codeforces.com/problemset/problem/1611/A
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
    map<char, bool>mp;
    mp['2'] = true;
    mp['4'] = true;
    mp['6'] = true;
    mp['8'] = true;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        bool found = false;
        for(int i=0;i<n;i++){
            if(mp[s[i]])found = true;
        }
        if(!found)cout<<-1<<"\n";
        else if(mp[s[n-1]])cout<<0<<"\n";
        else if(mp[s[0]])cout<<1<<"\n";
        else cout<<2<<"\n";


    }


    return 0;
}