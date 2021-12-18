//https://dmoj.ca/problem/ccc07j4
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
    vector<int>freq1(26), freq2(26);
    getline(cin, s);

    getline(cin, t);

    for(char c: s){
        if(c!=' '){
            freq1[c-'A']++;
        }
    }
    for(char c:t){
        if(c!=' '){
            freq2[c-'A']++;
        }
    }
    bool found = true;
    for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i])found = false;
    }

    cout<<(found ? "Is an anagram.\n" : "Is not an anagram.\n");


    return 0;
}