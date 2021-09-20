//https://codeforces.com/problemset/problem/1466/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        string s; cin>>s;
        int n = s.length();
        int ans = 0;
        vector<int>temp;
        for(int i=97;i<=122;i++){
            temp.push_back(i);
        }
        for(int i=1;i<=n;i++){
            
            if(s[i]==s[i-1]){
                vector<bool>res(26);
                res[s[i-1]-97] = true;
                if(i>=2) res[s[i-2]-97] = true;
                if(i<=n-2) res[s[i+1]-97] = true;
                if(i<=n-3) res[s[i+2]-97] = true;
                ans++;
                char change = 'a';
                while(true){
                    if(!res[change-97])break;
                    change++;
                }
                s[i] = change;


            }
            else if(i>=2){
                vector<bool>res(26);
                if(s[i]==s[i-2]){
                    res[s[i-2]-97] = true;
                    res[s[i-1]-97] = true;
                    if(i<=n-2) res[s[i+1]-97] = true;
                    if(i<=n-3) res[s[i+2]-97] = true;
                    ans++;
                    char change = 'a';
                    while(true){
                        if(!res[change-97])break;
                        change++;
                    }
                    s[i] = change;          
                }
                
            }
        }
        cout<<ans<<"\n";

    }
    


    return 0;
}