//https://dmoj.ca/problem/ccc02j2
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

    set<char>arr{'a','e','i','o','u','y'};

    while(true){
        string s; cin>>s;
        if(s == "quit!")break;
        int n = s.length();
        if(n <= 4){
            cout<<s<<"\n";
            continue;
        }

        if(arr.find(s[n-3]) == arr.end() && s.substr(n-2) == "or"){
            string temp = "";
            temp += s.substr(0,n-2);
            temp += "our";
            cout<<temp<<"\n";
        }
        else cout<<s<<"\n";
        
        

    }

    return 0;
}
