//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        string s; cin>>s;

        bool use = false;

        string a = "";
        string b = "";

        for(int i=0;i<n;i++){
            if(s[i]=='2'){
                if(use){
                    b+='2';
                    a+='0';
                    continue;
                }
                a+='1';
                b+='1';
            }
            else if(s[i]=='0'){
                a+='0';
                b+='0';
            }
            else{
                if(!use){
                    a+='1';
                    b+='0';
                }
                else{
                    a+='0';
                    b+='1';
                }
                use = true;

            }
        }
        cout<<a<<"\n"<<b<<"\n";

    }



  

    return 0;
}