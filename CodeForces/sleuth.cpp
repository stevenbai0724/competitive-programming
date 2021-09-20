//https://codeforces.com/problemset/problem/49/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string s; std::getline(std::cin,s);
    
    for(int i=s.length()-1;i>=0;i--){
        char c = s[i];
        
        if((c!='?') && ((int)c!=32) && (c=='a' || c=='e'||c=='i'||c=='o'||c=='u'||c=='y'||c=='A' || c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')){
            cout<<"YES";
            return 0;
        }
        else if(((int)c!=32) && (c!='?')){
            cout<<"NO"<<"\n";
            return 0;
        }
        
    }

    return 0;

}