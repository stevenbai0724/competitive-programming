//https://dmoj.ca/problem/ccc04j4
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

    string key, temp;
    getline(cin, key);
    getline(cin, temp);

    string s = "";

    for(char c: temp){
        if(c >= 'A' && c <= 'Z'){
            s += c;
        }
    }
    int keyLen = key.length();
    int sLen = s.length();
    for(int i=0;i<keyLen;i++){
        int shift = key[i] - 'A';
        for(int j=i;j<sLen;j+=keyLen){
            char newc = s[j] + shift;
            if(newc > 'Z') newc -= 26;
            s[j] = newc;
        }
    }

    cout<<s<<"\n";

    return 0;
}