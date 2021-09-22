//https://codeforces.com/problemset/problem/118/A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int n = s.length();

    for(int i=0;i<n;i++){
        if((int)s[i]<=90){
            s[i] += 32;
        }
    }

    string ans = "";

    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y')continue;
        ans += '.';
        ans += s[i];
    }

    cout<<ans<<"\n";

    return 0;
}