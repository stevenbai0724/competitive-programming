//https://codeforces.com/problemset/problem/32/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    string ans = "";

    for(int i =0;i<s.length();i++){
        if(s[i]=='.')ans+='0';
        else{
            if(s[i+1]=='.'){
                ans+='1';
                i++;
            }
            else{
                ans+='2';
                i++;
            }
        }
    }
    cout<<ans;

    return 0;
}