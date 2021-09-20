#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    int t; cin>>t;

    for(t; t>0;t--){
        int x,y;
        cin>>x>>y;
        int m = max(x, y);
        int ans = 0;
        if((m*m)%2 ==1){
            if(x>y){
                ans = (m*m)-(m-1) - (m-y);
            }
            else if(x<y){
                ans = (m*m) - (x-1);
            }
            else ans = (m*m) - (m-1);
        }
        else{
            if(x>y){
                ans = (m*m) - (y-1);
            }
            else if(x<y){
                ans = (m*m) - (m-1) - (m-x);
            }
            else ans = (m*m) - (m-1);
        }
        cout<<ans<<"\n";


    }


    return 0;
}