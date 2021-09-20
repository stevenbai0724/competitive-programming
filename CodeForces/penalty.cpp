//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        string s; cin>>s;
        if(s=="1111111111" || s=="0000000000"){
            cout<<"10\n";
            continue;
        }

        string eWin = s;
        string oWin = s;

        for(int i=0;i<10;i++){
            if(s[i]=='?'){
                if(i%2==0){
                    eWin[i] = '1';
                    oWin[i] = '0';
                }
                else{
                    eWin[i] = '0';
                    oWin[i] = '1';
                }
            }
        }
        int ans = 1e18;
        if(true){
            int oLeft = 5;
            int eLeft = 5;
            int e = 0, o = 0;
            for(int i=0;i<10;i++){

                if(i%2==0){
                    eLeft--;
                    if(eWin[i]=='1')e++;
                }
                else{
                    oLeft--;
                    if(eWin[i]=='1')o++;
                }
                if(e>oLeft+o || o>eLeft +e)ans = min(ans, i+1);
            }
        }
        if(true){
            int oLeft = 5;
            int eLeft = 5;
            int e = 0; int o = 0;
            for(int i=0;i<10;i++){

                if(i%2==0){
                    eLeft--;
                    if(oWin[i]=='1')e++;
                }
                else{
                    oLeft--;
                    if(oWin[i]=='1')o++;
                }
                if(e>oLeft+o || o>eLeft +e)ans = min(ans, i+1);
            }
        }
        if(ans==1e18)cout<<10<<"\n";
        else cout<<ans<<"\n";

    }
    return 0;
}