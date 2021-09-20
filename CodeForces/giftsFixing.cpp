//https://codeforces.com/problemset/problem/1399/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n+1);
        vector<int>b(n+1);
        int moves = 0;
        int ansA = 1e9;
        int ansB = 1e9;

        for(int i=1;i<=n;i++){
            cin>>a[i];
            ansA = min(ansA, a[i]);
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
            ansB = min(ansB, b[i]);
        }
        for(int i=1;i<=n;i++){
            int x = a[i] - ansA;
            int y = b[i] - ansB;
            moves+= (x+y-min(x,y));
        }   

        cout<<moves<<"\n";
        
    }

    
    return 0;
}