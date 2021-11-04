//https://dmoj.ca/problem/ecoo12r3p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string

int solve(char a, string b, string c){

    if(b.length()==1 && c.length()==1){
        int x = stoi(b);
        int y = stoi(c);
        if(a=='+')return x+y;
        if(a=='-')return x-y;
        if(a=='*')return x*y;
        if(a=='q')return x/y;
        if(a=='r')return x%y;
    }
    int x;
    int y;
    if(b.length()!=1){

        int n = b.length();
        
        int R = 0;
        int L = 0;
        int j = 3;
        for(int i=3;i<n;i++){
            R += b[i]==')';
            L += b[i]=='(';
            if(R==L){
                j=i;
                break;
            }

        }
        string temp = "";

        for(int i=j+2;i<n-1;i++){
            temp+=b[i];
        }
        x = solve(b[1], b.substr(3, j-2), temp);
    }
    else x = stoi(b);

    if(c.length()!=1){
        int n = c.length();
        
        int R = 0;
        int L = 0;
        int j = 3;
        for(int i=3;i<n;i++){
            R += c[i]==')';
            L += c[i]=='(';
            if(R==L){
                j=i;
                break;
            }

        }
        string temp = "";

        for(int i=j+2;i<n-1;i++){
            temp+=c[i];
        }
        y = solve(c[1], c.substr(3, j-2), temp);
    }
    else y = stoi(c);

    if(a=='+')return x+y;
    if(a=='-')return x-y;
    if(a=='*')return x*y;
    if(a=='q')return x/y;
    if(a=='r')return x%y;

    return -1;

}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 10;
    while(t--){

        string scam; getline(cin, scam);
        int n = scam.length();
        string s = "";
        bool good = false;
        for(int i=n-1;i>=0;i--){
            if(scam[i]!=' ')good = true;
            if(good)s+=scam[i];
        }
        reverse(s.begin(), s.end());
        n = s.length();
        assert(s[n-1]==')');
        
        int R = 0;
        int L = 0;
        int j = 3;
        for(int i=3;i<n;i++){
            R += s[i]==')';
            L += s[i]=='(';
            if(R==L){
                j=i;
                break;
            }

        }
        string temp = "";

        for(int i=j+2;i<n-1;i++){
            temp+=s[i];
        }

        cout<<solve(s[1], s.substr(3, j-2), temp)<<"\n";

        
    }



    return 0;
}