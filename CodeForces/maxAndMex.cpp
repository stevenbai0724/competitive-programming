#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        int mex = 0;
        int mx = 0;
        set<int>s;

        for(int j=1;j<=n;j++){
            int x; cin>>x;

            mx = max(mx, x);

            s.insert(x);

        }
        for(int x: s){
            if(x==mex)mex++;
        }
        if(k==0){
            cout<<s.size()<<"\n";
            continue;
        }
        int c = ceil((mex+mx)/2.0);

        if(c<=mx){
            s.insert(c);
            cout<<s.size()<<"\n";
            continue;
        }
        cout<<s.size()+k<<"\n";
    }

    return 0;
    
}