#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum = a+b+c;
        int mn = min(a, (min(b,c)));

        if(sum%9==0 && mn>=sum/9){
            cout<<"YES"<<"\n";
        }
        else cout<<"NO"<<"\n";
        
    }
    return 0;
}