//https://codeforces.com/problemset/problem/1365/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;

        vector<int>a(n+1), b(n+1), sorted;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        bool zero = false, one = false;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            zero |= b[i] == 0;
            one |= b[i] == 1;
        }
        sorted = a;
        sort(sorted.begin(), sorted.end());
        if(zero && one){
            cout<<"Yes\n";
        }
        else if(sorted == a){
            cout<<"Yes\n";
        }
        else cout<<"No\n";


    }


    return 0;
}