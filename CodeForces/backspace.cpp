//https://codeforces.com/problemset/problem/1553/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    while(t--){
        string s, t;
        cin>>s>>t;

        int n = s.length();
        int m = t.length();

        int cnt = 0;

        int p1 = n-1;
        int p2 = m-1;

        while(true){
            if(p1<0 || p2<0)break;

            if(s[p1]==t[p2]){
                cnt++;
                p1--;
                p2--;
            }
            else{
                p1-=2;
            }
        }
        if(cnt!=m)cout<<"NO\n";
        else cout<<"YES\n";

    }


    return 0;
}