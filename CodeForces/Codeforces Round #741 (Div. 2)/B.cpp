//https://codeforces.com/contest/1562/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    
    while(t--){
        int n; cin>>n;
        map<int, int>mp;
        string s; cin>>s;

        int mn = 1e9;
        string ans = "";

        for(int i=0;i<n;i++){
            mp[s[i]-48] ++;
            if(mp[s[i]-48]>=2){
                if(2<mn){
                    mn = 2;
                    ans = "";
                    ans += s[i];
                    ans += s[i];
                }
             
            }
            if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
                mn = 1;
                ans = s[i];
            }
            if(i>0){
                if(s[i]=='2' || s[i]=='5'){
                    if(2<mn){
                        mn = 2;
                        ans = "";
                        ans += s[i-1];
                        ans += s[i];
                    }
                }
            }
        }
        if(mn!=1e9){
            cout<<mn<<"\n";
            cout<<ans<<"\n";
        }
        else cout<<2<<"\n"<<s[0]<<7<<"\n";



    }


    return 0;
}