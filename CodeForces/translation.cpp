//https://codeforces.com/problemset/problem/41/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s, t;
    cin>>s>>t;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(s[i]!=t[l-i-1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}