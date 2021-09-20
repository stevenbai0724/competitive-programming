//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            int temp = x;
            int cnt = 0;
            if(x>=(d*10) || d==1){
                cout<<"YES\n";
                continue;
            }
            while(cnt<=10 && x>0){
                if(x%10==d ||(x%10==0&&cnt>0)){
                    cout<<"YES\n";
                    goto nxt;
                }
                cnt++;
                x-=d;
            }

            cout<<"NO\n";
            nxt:; 
        }
    }
    return 0;

}