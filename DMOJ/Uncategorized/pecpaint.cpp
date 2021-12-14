//https://dmoj.ca/problem/pecpaint
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

    gp_hash_table<string, char>mp;
    //primary + primary
    mp["BR"] = 'P';
    mp["RY"] = 'O';
    mp["BY"] = 'G';

    //secondary + secondary
    mp["OP"] = 'R';
    mp["GP"] = 'B';
    mp["GO"] = 'Y';

    //primary + secondary
    mp["BP"] = 'W';
    mp["BO"] = 'W';
    mp["BG"] = 'W';
    mp["PR"] = 'W';
    mp["OR"] = 'W';
    mp["GR"] = 'W';
    mp["PY"] = 'W';
    mp["OY"] = 'W';
    mp["GY"] = 'W';

    //same
    mp["WW"] = 'W';
    mp["PP"] = 'P';
    mp["OO"] = 'O';
    mp["GG"] = 'G';
    mp["BB"] = 'B';
    mp["RR"] = 'R';
    mp["YY"] = 'Y';

    //white
    mp["BW"] = 'B';
    mp["GW"] = 'G';
    mp["WY"] = 'Y';
    mp["RW"] = 'R';
    mp["OW"] = 'O';
    mp["PW"] = 'P';
    

    int n; cin>>n;
    string s;cin>>s;
    string ans = "";

    for(int t = 1; t < n ; t++){
        for(int i=0;i<s.length()-1;i++){
            char a = s[i];
            char b = s[i+1];

            string x = "";
            x += a;
            x += b;
            sort(x.begin(), x.end());
            ans += mp[x];
        }
        
        s = ans;
        ans = "";
    }
    cout<<s<<"\n";
    


    return 0;
}