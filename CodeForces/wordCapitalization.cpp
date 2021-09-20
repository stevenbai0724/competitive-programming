//https://codeforces.com/problemset/problem/281/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    if((int)s[0]<=90) cout<<s;
    else{
        s[0] = (char)((int)(s[0])-32);
        cout<<s;
    }

    return 0;
}