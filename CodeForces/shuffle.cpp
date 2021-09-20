//https://codeforces.com/problemset/problem/1366/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n, x, m;
        cin>>n>>x>>m;

        int minL = x;
        int maxR = x;

        while(m--){
            int l, r;
            cin>>l>>r;

            if(l<=maxR && r>=minL){
                minL = min(minL, l);
                maxR = max(maxR, r);
            }
        }

        cout<<maxR-minL+1<<"\n";

    }


    return 0;
}