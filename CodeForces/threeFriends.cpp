//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
    
        int a, b, c;
        cin>>a>>b>>c;
        
        int ans = 1e18;
        for(int i=a-1;i<=a+1;i++){
            for(int j=b-1;j<=b+1;j++){
                for(int k=c-1;k<=c+1;k++){
                    ans = min(ans, abs(i-j)+abs(i-k)+abs(j-k));
                }
            }
        }
        cout<<ans<<"\n";

    }


    return 0;
}