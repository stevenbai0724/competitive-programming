#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        int ans = 0;

        for(int i=0;i<=1e5;i++){
            
            string s = to_string(n+i);

            for(auto c: s){
                if(c!='0'){
                    int x = c-48;
                    if((n+i)%x!=0)goto notFound;
                }
            }
            ans = n+i;
            goto nxt;

            notFound:;


        }
        continue;

        nxt:;
        cout<<ans<<"\n";





    }



    return 0;
}