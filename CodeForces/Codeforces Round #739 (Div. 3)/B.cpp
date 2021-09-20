//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int diff = abs(a-b);
        int len = diff*2;

        if(c>len || b>len || a>len){
            cout<<-1<<"\n";
        }
        else if(c-diff>0){
            cout<<c-diff<<"\n";
        }
        else if(c+diff<=len){
            cout<<c+diff<<"\n";
        }
        else (assert(false));
    }


    return 0;
}