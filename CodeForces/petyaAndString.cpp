//https://codeforces.com/problemset/problem/112/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s1, s2;
    cin>>s1>>s2;
    
    for(int i=0;i<s1.length();i++){
        if((int)s1[i]>=97) s1[i] = (char)((int)s1[i]-32);
        if((int)s2[i]>=97) s2[i] = (char)((int)s2[i]-32);
    }

    for(int i=0;i<s1.length();i++){
        if((int)s1[i]>(int)s2[i]){
            cout<<1;
            return 0;
        }
        if((int)s1[i]<(int)s2[i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}