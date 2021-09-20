//https://cses.fi/problemset/task/1754/
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    for(t;t>0;t--){
        int x, y;
        cin>>x>>y;
        if((x+y)%3==0 &&x <=2*y && y<=x*2)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }


    return 0;
}