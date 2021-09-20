//https://codeforces.com/problemset/problem/1553/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int time; cin>>time;

    while(time--){
        string s, t;
        cin>>s>>t;
        int n, m;
        n = s.length();
        m = t.length();

        for(int i=0;i<n;i++){
            for(int j=0;j<=max((int)1, m-1) && i+j <=n; j++){
                string check = "";

                check += s[i];

                int rLen = j;
                int lLen = m-1-rLen;

                int k = i;

                if(rLen>0)k++;

                for(;k<n && rLen>0;k++){
                    check+=s[k];
                    rLen--;
                }

                k--;

                if(check.length()>1)k--;

                for(;k>=0 && lLen>0;k--){
                    check+=s[k];
                    lLen--;
                }
      
                if(check==t){
                    cout<<"YES\n";
                    goto nxt;
                }



            }
        }
        cout<<"NO\n";
        nxt:;
    }


    return 0;
}