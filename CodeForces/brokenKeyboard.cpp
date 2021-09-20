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
        string s; cin>>s;

        int n = s.length();
        if(n==1){
            cout<<s<<"\n";
            continue;
        }
        vector<bool>ans(26);

        int start = 0;
        int end = 0;

        for(int i=0;i<n;i++){   
            int j = i;
            while(s[j+1]==s[i] && j+1<n){
                j++;
            }

            if((j-i+1)&1)ans[s[i]-'a'] = true;  
            i = j;

        }
        for(int i=0;i<26;i++){
            if(ans[i])cout<<char(i+'a');
        }
        cout<<"\n";

    }


    return 0;
}