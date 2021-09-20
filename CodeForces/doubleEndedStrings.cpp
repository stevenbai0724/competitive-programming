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
        string str1, str2;
        cin>>str1>>str2;
        if(str1>str2){
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        int n = str1.length();
        int m = str2.length();

        int keep = 0;
        for(int len = 1; len<= n; len++){
            for(int i=0;i<n-len+1;i++){
                string temp = str1.substr(i,len);
                bool found = false;
                for(int j=0;j<m-len+1;j++){
                    if(str2.substr(j,len)==temp)found = true;
                }
                if(found)keep = len;
            }
        }
        cout<<(n+m)-keep-keep<<"\n";
    }

    return 0;
}