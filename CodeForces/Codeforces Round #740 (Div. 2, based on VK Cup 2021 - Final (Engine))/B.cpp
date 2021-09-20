//https://codeforces.com/problemset/problem/1561/B
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        int a, b;
        cin>>a>>b;

        set<int>st;

        if(true){
            int p = (a+b+1)/2;
            int q = (a+b)/2;

            for(int x=0;x<=p;x++){
                int y = x+q-a;
                if(0<=y && y<=q)st.insert(x+y);
            }
        }
        if(true){
            int q = (a+b+1)/2;
            int p = (a+b)/2;

            for(int x=0;x<=p;x++){
                int y = x+q-a;
                if(0<=y && y<=q)st.insert(x+y);
            }
        }
        cout<<st.size()<<"\n";
        for(int x: st)cout<<x<<" ";
        cout<<"\n";
    }


    return 0;
}