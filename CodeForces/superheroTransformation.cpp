//https://codeforces.com/problemset/problem/1111/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin>>s>>t;
    string vowel = "aeiou";

    if(s.length()!=t.length()){
        cout<<"No";
        return 0;
    }
    for(int i=0;i<s.length();i++){
        size_t found1 = vowel.find(s[i]);
        size_t found2 = vowel.find(t[i]);
        
        if((found1 != string::npos && found2 ==string::npos) ||( found1==string::npos && found2 != string::npos)){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    
    return 0;
}