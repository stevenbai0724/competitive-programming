//https://codeforces.com/contest/755/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define string std::string

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    set<int>s;
    int ans = 0;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==i)ans++;
        else s.insert(x);
    }
    ans += (s.size()/2);
    cout<<ans<<"\n";


    return 0;
}