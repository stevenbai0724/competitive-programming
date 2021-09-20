//https://codeforces.com/problemset/problem/61/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin>>s>>t;
    string ans = "" ;
    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i])ans+='1';
        else ans+='0';
    }
    cout<<ans;
    return 0;

}