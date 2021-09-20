//https://codeforces.com/problemset/problem/1469/A
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    

    int t; cin>>t;

    while(t--){
        
        int n; cin>>n;
      
        int mxRed = 0;
        int sum = 0;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            sum += x;
            mxRed = max(mxRed, sum);
        }
        sum = 0;

        int m; cin>>m;

        int mxBlue = 0;
        for(int i=1;i<=m;i++){
            int x; cin>>x;
            sum += x;
            mxBlue = max(mxBlue, sum);
        }
        cout<<(max((int)0,mxBlue + mxRed))<<"\n";



    }


    return 0;
}