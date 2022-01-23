//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int g, p;
    cin>>g>>p;

    set<int>s;

    for(int i=-g;i<=-1;i++){
        s.insert(i);
    }

    for(int i=1;i<=p;i++){
        int x; cin>>x;
        x *= -1;
        if(s.lower_bound(x) == s.end()){
            cout<<i-1<<"\n";
            return 0;
        }
        else{
            s.erase(s.lower_bound(x));
        }
    }
    cout<<p<<"\n";
    
    return 0;
}