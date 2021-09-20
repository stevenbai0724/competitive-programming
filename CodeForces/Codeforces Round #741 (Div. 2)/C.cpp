//https://codeforces.com/problemset/problem/1562/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        string s = "8";
        string temp; cin>>temp;

        s += temp;

        for(int i=1;i<=n/2;i++){
            if(s[i]=='0'){
                cout<<i<<" "<<n<<" "<<i+1<<" "<<n<<"\n";
                goto nxt;
            }
        }
        for(int i=n/2 + 1; i<=n;i++){
            if(s[i]=='0'){
                cout<<1<<" "<<i<<" "<<1<<" "<<i-1<<"\n";
                goto nxt;
            }
        }
        cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<"\n";

        nxt:;
    }


    return 0;
}