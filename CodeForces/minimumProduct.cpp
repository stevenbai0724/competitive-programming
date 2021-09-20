//https://codeforces.com/problemset/problem/1409/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        
        int a ,b, x, y, n;

        cin>>a>>b>>x>>y>>n;

        int ans1 = 1e18;
        int ans2 = 1e18;


        if (true){
            int ops = n;
            int tA = a, tB = b, tX = x, tY = y;

            if(tA>tX){
                int mn = min(ops, tA-tX);
                ops-=mn;
                tA -= mn;

            }
            if(tB>tY){
                int mn = min(ops, tB-tY);
                ops-=mn;
                tB -= mn;
            }
            ans1 = tA * tB;

        }

        
        if (true){
            int ops = n;
            int tA = a, tB = b, tX = x, tY = y;

            if(tB>tY){
                int mn = min(ops, tB-tY);
                ops-=mn;
                tB -= mn;
            }

            if(tA>tX){
                int mn = min(ops, tA-tX);
                ops-=mn;
                tA -= mn;

            }

            ans2 = tA * tB;

        }
        cout<<min(ans1, ans2)<<"\n";
    }

    return 0;   
}