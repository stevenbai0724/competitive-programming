//https://codeforces.com/problemset/problem/202/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    string s; cin>>s;

    vector<int>arr(140);
    int ans = 0;
    char c;
    for(int i=0;i<s.length();i++){
        arr[(int)s[i]]++;
    }
    for(int i=122;i>=97;i--){
        if(arr[i]!=0){
            c = (char)i;
            ans = arr[i];
            break;
        }
    }
    for(int i = 1;i<=ans;i++){
        cout<<c;
    }
    return 0;
}