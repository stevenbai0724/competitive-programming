//https://codeforces.com/problemset/problem/1547/E
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int>pos(k+1);
        vector<int>temp(k+1);

        for(int i=1;i<=k;i++){
            cin>>pos[i];
        }
        for(int i=1;i<=k;i++){
            cin>>temp[i];
        }
        vector<int>c(n+1, 1e18);

        for(int i=1;i<=k;i++){
            c[pos[i]] = temp[i];
        }

        vector<int>l(n+2, 1e18), r(n+2, 1e18);

        for(int i=1;i<=n;i++){
            l[i] = min(l[i-1]+1, c[i]);
        }
        for(int i=n;i>=1;i--){
            r[i] = min(r[i+1]+1, c[i]);
        }

        for(int i=1;i<=n;i++){
            cout<<min(r[i], l[i])<<" ";
        }
        cout<<"\n";


     

       
    }


    return 0;
}