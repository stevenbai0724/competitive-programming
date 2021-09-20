//https://codeforces.com/problemset/problem/1536/B//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    vector<set<string>>st(4);
    for(int i=97;i<=122;i++){
        string temp1 = "";
        temp1+= (char)i;
        st[1].insert(temp1);

        for(int j=97;j<=122;j++){
            string temp2 = temp1;
            temp2+= (char)j;
            st[2].insert(temp2);

            for(int k=97;k<=122;k++){
                string temp3 = temp2;
                temp3 += (char)k;
                st[3].insert(temp3);
            }
        }
    }
   
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        string ans = "zzzzzz";
        unordered_map<string, bool>mp;
    

        for(int len = 1; len<=3; len++){
            for(int i=0;i<n-len+1;i++){
                string temp = "";
                for(int j=i;j<i+len;j++){
                    temp+=s[j];
                }
                mp[temp] = true;
            }
        }
        for(int i=1;i<=3;i++){
            for(auto x : st[i]){
                
                if(mp[x])continue;
                if(x<ans )ans = x;
            }
            if(ans!="zzzzzz"){
                cout<<ans<<"\n";
                goto nxt;
            }
        }

        

        nxt:;
    }



    return 0;
}