#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        int sum = 0;
        bool odd = false;
        bool even = false;

        for(x;x>0;x--){
            int m; cin>>m;
            sum+=m;
            if(m%2==0) even = true;
            else odd = true;
        }
        if(sum%2==1){
            cout<<"YES"<<"\n";
            continue;
        }
        if(odd && even){
            cout<<"YES"<<"\n";
            continue;
        }
        cout<<"NO"<<"\n";

        
    }

    return 0;
}