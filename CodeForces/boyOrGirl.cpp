//https://codeforces.com/problemset/problem/236/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    set<char>c;

    for(int i=0;i<s.length();i++){
        c.insert(s[i]);
    }
    if(c.size()%2==1)cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";


    return 0;
}