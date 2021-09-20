//https://codeforces.com/problemset/problem/59/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string s; cin>>s;
    int loCount = 0;
    int upCount = 0;    
    string ans = "";
    for(int i=0;i<s.length();i++){
        if((int)s[i]<=90)upCount++;
        else loCount++;
    }
    if(loCount>=upCount){
        for(int i =0;i<s.length();i++){
            if((int)s[i]<=90) ans+= (char)((int)s[i]+32);
            else ans+= s[i];
        }
    }
    else{
        for(int i =0;i<s.length();i++){
            if((int)s[i]>90) ans+= (char)((int)s[i]-32);
            else ans+= s[i];
        }
    }
    cout<<ans;

    return 0;

}