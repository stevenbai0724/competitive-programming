//https://codeforces.com/problemset/problem/1555/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int w, h;
        cin>>w>>h;
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        int x, y;
        cin>>x>>y;

        int case1 = 1e18, case2 = 1e18, case3 = 1e18, case4 = 1e18;

        if(x2-x1+x<=w){
            case1 = max((int)0, x-x1);
            case2 = max((int)0, x2-(w-x));
        }
        if(y2-y1+y<=h){
            case3 = max((int)0, y-y1);
            case4 = max((int)0, y2-(h-y));
        }
        int ans = min(case1, min(case2, min(case3, case4)));
        if(ans==1e18)cout<<-1<<"\n";
        else cout<<ans<<"\n";

    }


    return 0;
}