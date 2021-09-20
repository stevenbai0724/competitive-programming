//
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int xa, ya, xb, yb, xf, yf;
        cin>>xa>>ya>>xb>>yb>>xf>>yf;

        if(xa==xb && xf == xa){
            if((ya <= yf && yb >= yf) || (yb <= yf && ya >= yf)){
                cout<<abs(ya-yb)+2<<"\n";
            }
            else cout<<abs(ya-yb)<<"\n";
        }
        else if(ya==yb && yf == ya){
            if((xa <= xf && xb >= xf) || (xb <= xf && xa >= xf)){
                cout<<abs(xa-xb)+2<<"\n";
            }
            else cout<<abs(xa-xb)<<"\n";
        }
        else{
            cout<<abs(xa-xb)+abs(ya-yb)<<"\n";
        }
    }

    return 0;
}