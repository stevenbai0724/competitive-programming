//https://codeforces.com/contest/755/problem/B
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    set<string>s;
    int match = 0;
    for(int i=1;i<=n;i++){
        string str; cin>>str;
        s.insert(str);
    }
    for(int i=1;i<=m;i++){
        string str;cin>>str;
        if(s.find(str)!=s.end()){
            match++;
        }
    }
    int good = n-match;
    int bad  = m-match;

    if(match!=0){
        if(match&1)good++;
    }

    if(good>bad)cout<<"YES";
    else cout<<"NO";



    return 0;
}