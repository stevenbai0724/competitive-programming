//https://codeforces.com/problemset/problem/1526/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        for(int i=1;i<=15;i++){
            if(n%11==0){
                cout<<"YES\n";
                goto nxt;
            }
            n -= 111;
            if(n<0)break;
        }

        cout<<"NO\n";


        nxt:;


    }


    return 0;
}