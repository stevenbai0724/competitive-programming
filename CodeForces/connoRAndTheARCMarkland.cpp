//
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, s, k;        
        cin>>n>>s>>k;
        map<int, bool>mp;

        int up = 0, down = 0;

        while(k--){
            int x; cin>>x;
            mp[x] = true;
        }
        bool upFound = false , downFound = false;
        for(int i=s;i<=s+1001 && i<=n;i++){
            if(!mp[i]){
                upFound = true;
                break;
            }
            up++;
        }
        for(int i=s;i>=s-1001 && i>=1;i--){
            if(!mp[i]){
                downFound = true;
                break;
            }
            down++;
        }
        if(!upFound)up = 1e18;
        if(!downFound)down = 1e18;
        cout<<min(up, down)<<"\n";


    }


    return 0;
}