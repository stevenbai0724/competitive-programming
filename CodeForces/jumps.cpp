//https://codeforces.com/problemset/problem/1455/B
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
        int x; cin>>x;

        int pos = 0;


        for(int i=1;i<=3000;i++){
            pos = (i*(i+1)/2);
            if(pos==x){
                cout<<i<<"\n";
                goto nxt;
            }
            if(x+1 == pos){
                cout<<i+1<<"\n";
                goto nxt;
            }
            if(pos>x){
                cout<<i<<"\n";
                goto nxt;
            }
        }

        nxt:;
    }




    return 0;
}