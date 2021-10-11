//https://codeforces.com/contest/1579/problem/A
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
        string s; cin>>s;
        int A = 0;
        int B = 0;
        int C = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='A')A++;
            else if(s[i]=='B')B++;
            else C++;
        }
        if(A+C == B )cout<<"Yes\n";
        else cout<<"No\n";
    }


    return 0;
}