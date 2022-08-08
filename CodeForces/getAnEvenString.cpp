//https://codeforces.com/problemset/problem/1660/C
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
        int n = s.length();

        vector<bool>arr(26);

        for(auto c: s){
            if(!arr[c - 'a']){
                arr[c - 'a'] = true;
            }
            else{
                n -=2;
                for(int i = 0; i<26; i++){
                    arr[i] = false;
                }
            }
        }
        cout<<n<<"\n";


    }

    return 0;
}
