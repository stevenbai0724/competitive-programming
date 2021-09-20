//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int t; cin>>t;
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;
        int mx = max(a,b);
        if(k==1){
            cout<<0<<endl;
            int x;
            cin>>x>>x;
            continue;
        }
        int ans = (k-1)*(k)/2;
        
        set<int>s1;
        set<int>s2;
        for(int i=1;i<=k;i++){
            int x;cin>>x;
            s1.insert(x);
        }
        for(int i=1;i<=k;i++){
            int x; cin>>x;
            s2.insert(x);
        }
        cout<<ans-(k-s1.size())-(k-s2.size())<<endl;


    }
   
    return 0;

}