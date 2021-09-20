//https://codeforces.com/problemset/problem/1244/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int first = 1e9;
        int last = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                first = min(first, i+1);
                last = max(last, i+1);
            }
        }
        if(last==0){
            cout<<n<<"\n";
            continue;
        }
        cout<<max(last*2, (n-first+1)*2)<<"\n";

    }
    return 0;

}