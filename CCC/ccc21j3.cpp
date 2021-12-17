//https://dmoj.ca/problem/ccc21j3
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

    string prev = "";

    while(true){
        string s; cin>>s;
        int sum = s[0] + s[1] - '0' - '0';

        if(s == "99999")break;

        if(sum&1){
            cout<<"left "<<s.substr(2)<<"\n";
            prev = s;
        }
        else if(sum!=0){
            cout<<"right "<<s.substr(2)<<"\n";
            prev = s;
        }
        else{
            int newSum = prev[0] + prev[1] - '0' - '0';
            assert(newSum != 0);
            if(newSum&1){
                cout<<"left  "<<s.substr(2)<<"\n";
            }
            else{
                cout<<"right "<<s.substr(2)<<"\n";
            }
        }
    }


    return 0;
}