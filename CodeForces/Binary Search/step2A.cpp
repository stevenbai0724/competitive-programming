#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    
    int w,h,n;
    cin >>w>>h>>n;
    int l = 0, r = (int)1e18;

    while(l+1<r){
        int m = (l+r)/2;

        if((m/w)*(m/h) <n) l = m;
        else r = m;
    }
    cout<<r;
    return 0;
}
    