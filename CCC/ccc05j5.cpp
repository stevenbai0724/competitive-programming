//https://dmoj.ca/problem/ccc05j5
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    while(true){
        string s; getline(cin, s);
        if(s=="X")break;
        if(s=="A"){
            cout<<"YES\n";
            continue;
        }
        bool found = false;
        while(true){
            found = false;
            int len = s.length();
            if(len<3)break;

            for(int i=0;i<len-2;i++){
                if(s.substr(i,3)=="ANA" || s.substr(i,3)=="BAS"){
                    string L = "";
                    string R = "";
                    if(i>0)L = s.substr(0,i);
                    if(i+3<len) R = s.substr(i+3);
                    found = true;
                    s = "";
                    s += L;
                    s +="A";
                    s += R;
                    break;

                }
            }
            if(!found)break;

        }
        if(s=="A")cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}